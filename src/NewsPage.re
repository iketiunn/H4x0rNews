open ReactNative;
open ReactNavigation;
open Util;

type state = {
  newsList: list(Data.news),
  page: int,
  isLoading: bool,
  timeout: bool,
};
type action =
  | Init
  | Loaded((int, list(Data.news)))
  | Loading
  | Timeout;
let component = ReasonReact.reducerComponent("App");
[@react.component]
let make = (~navigation: Navigation.t, ()) => {
  let loadNews = ({ReasonReact.state, send}) =>
    if (state.page < 10 && !state.isLoading) {
      let newPage = state.page + 1;
      Js.Promise.(
        withTimeout(
          Data.fetchNewList(~id=string_of_int(newPage), ()),
          30000,
        )
        |> then_(newsList => resolve(send(Loaded((newPage, newsList)))))
        |> catch(_err => resolve(send(Timeout)))
        |> ignore
      );
      send(Loading);
    };
  let reload = ({ReasonReact.state: _state, send}) => {
    send(Init);
    Js.Promise.(
      withTimeout(Data.fetchNewList(~id=string_of_int(1), ()), 30000)
      |> then_(newsList => resolve(send(Loaded((1, newsList)))))
      |> catch(_err => resolve(send(Timeout)))
      |> ignore
    );
  };
  let init = () => {newsList: [], page: 0, isLoading: false, timeout: false};
  ReactCompat.useRecordApi({
    ...component,
    initialState: init,
    didMount: loadNews,
    reducer: (action, state) =>
      switch (action) {
      | Init => ReasonReact.Update(init())
      | Loaded((newPage, newList)) =>
        ReasonReact.Update({
          page: newPage,
          newsList: List.append(state.newsList, newList),
          isLoading: false,
          timeout: false,
        })
      | Loading => ReasonReact.Update({...state, isLoading: true})
      | Timeout => ReasonReact.Update({...state, timeout: true})
      },
    render: self =>
      <SafeAreaView style=AppStyle.pageContainer>
        <View style=AppStyle.NewsPage.newsContainer>
          {
            /***
             * If timeout, shows timeout wording
             * or shows news list
             */
            self.state.timeout ?
              <Text
                style=AppStyle.Common.textCenter
                value="Timeout...Tap Refresh Button to reload page"
                onPress={_ => reload(self)}
              /> :
              <NewsFlatList
                data={Array.of_list(self.state.newsList)}
                refreshing={self.state.isLoading}
                onRefresh={_ => reload(self)}
                onEndReached={_ => loadNews(self)}
                navigation
              />
          }
          <RefreshButton onPress={_ => reload(self)} />
        </View>
      </SafeAreaView>,
  });
};