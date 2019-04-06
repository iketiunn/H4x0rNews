open BsReactNative;

type state = {
  newsList: Data.newsList,
  page: int,
  isLoading: bool,
};
type action =
  | Loaded((int, Data.newsList))
  | Loading;
let component = ReasonReact.reducerComponent("App");
let make = (~navigation: Config.navigationProp, _children) => {
  let loadNews = ({ReasonReact.state, send}) =>
    if (state.page < 10 && !state.isLoading) {
      let newPage = state.page + 1;
      Js.Promise.(
        Data.fetchNewList(~id=string_of_int(newPage), ())
        |> then_(newsList => resolve(send(Loaded((newPage, newsList)))))
        |> ignore
      );
      send(Loading);
    };
  {
    ...component,
    initialState: () => {newsList: [], page: 0, isLoading: false},
    didMount: loadNews,
    reducer: (action, state) =>
      switch (action) {
      | Loaded((newPage, newList)) =>
        ReasonReact.Update({
          page: newPage,
          newsList: List.append(state.newsList, newList),
          isLoading: false,
        })
      | Loading => ReasonReact.Update({...state, isLoading: true})
      },
    render: self =>
      <SafeAreaView style=AppStyle.pageContainer>
        /* Header, title, back button */

          <View style=AppStyle.news>
            <NewsFlatList
              data={Array.of_list(self.state.newsList)}
              onEndReached={_ => loadNews(self)}
              navigation
            />
          </View>
          /*
           * Footer && ActivityIndicator
           */
          <View>
            {
              self.state.isLoading ?
                <ActivityIndicator
                  style=AppStyle.activityIndicator
                  size=`large
                /> :
                <View />
            }
          </View>
        </SafeAreaView>,
  };
};