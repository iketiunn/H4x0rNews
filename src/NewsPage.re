open BsReactNative;

type state = {
  newsList: list(Data.news),
  page: int,
  isLoading: bool,
};
type action =
  | Init
  | Loaded((int, list(Data.news)))
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
  /* let setNewsFlatListRef = (listRef, {ReasonReact.state, send}) =>
     self.send(SetNewsFlatListRef(listRef)); */
  let init = () => {newsList: [], page: 0, isLoading: false};
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
        })
      | Loading => ReasonReact.Update({...state, isLoading: true})
      },
    render: self =>
      <SafeAreaView style=AppStyle.pageContainer>
        <View style=AppStyle.news>
          <NewsFlatList
            data={Array.of_list(self.state.newsList)}
            refreshing={self.state.isLoading}
            onRefresh={
              _ => {
                self.send(Init);
                loadNews(self);
              }
            }
            onEndReached={_ => loadNews(self)}
            navigation
          />
          /*** Since back to top is not available due to ref api is not implement */
          <BackToTopButton
            onPress={
              _ => {
                self.send(Init);
                loadNews(self);
              }
            }
          />
        </View>
      </SafeAreaView>,
  };
};