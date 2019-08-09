open BsReactNative;
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
let make = (~navigation: Config.navigationProp, _children) => {
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
  {
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
        {
          if (self.state.timeout) {
            <View style=AppStyle.news>
              <Text
                style=AppStyle.Common.textCenter
                value="Timeout...Tap Back-To-Top Button to reload"
                onPress={_ => reload(self)}
              />
              <BackToTopButton onPress={_ => reload(self)} />
            </View>;
          } else {
            <View style=AppStyle.news>
              <NewsFlatList
                data={Array.of_list(self.state.newsList)}
                refreshing={self.state.isLoading}
                onRefresh={_ => reload(self)}
                onEndReached={_ => loadNews(self)}
                navigation
              />
              /*** Since back to top is not available due to ref api is not implement */
              <BackToTopButton onPress={_ => reload(self)} />
            </View>;
          }
        }
      </SafeAreaView>,
  };
};