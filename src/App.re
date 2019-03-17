/* Should be a entry for News List */
open BsReactNative;

type state = {
  newsList: Data.newsList,
  page: int,
  loading: bool,
};
type action =
  | Loaded((int, Data.newsList))
  | Loading;
/*| Scroll; */
let component = ReasonReact.reducerComponent("App");
let make = _children => {
  ...component,
  initialState: () => {newsList: [], page: 0, loading: false},
  didMount: self => {
    let newPage = self.state.page + 1;
    Js.Promise.(
      Data.fetchNewList(~id=string_of_int(newPage), ())
      |> then_(newsList => resolve(self.send(Loaded((newPage, newsList)))))
      |> ignore
    );
  },
  reducer: (action, state) =>
    switch (action) {
    | Loaded((page, newList)) =>
      ReasonReact.Update({
        ...state,
        page: state.page + page,
        newsList: List.append(state.newsList, newList),
      })
    | Loading => ReasonReact.Update({...state, loading: true})
    },
  render: self =>
    /*
     * Safe from notch, but weired on android(icons, and time missing!)
     */
    <SafeAreaView style=AppStyle.pageContainer>
      <View style=AppStyle.news>
        <NewsFlatList data={Array.of_list(self.state.newsList)} />
      </View>
    </SafeAreaView>,
};
let default = ReasonReact.wrapReasonForJs(~component, _jsProps => make([||]));