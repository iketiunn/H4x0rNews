open BsReactNative;

type state = {
  story: option(Data.story),
  isLoading: bool,
};
type action =
  | Loaded(option(Data.story))
  | Loading;
let component = ReasonReact.reducerComponent("Comments");
let make = (~storyId: int, _children) => {
  let loadComments = ({ReasonReact.state, send}) =>
    if (!state.isLoading) {
      Js.Promise.(
        Data.fetchStory(string_of_int(storyId))
        |> then_(story => resolve(send(Loaded(Some(story)))))
        |> ignore
      );

      send(Loading);
    };
  {
    ...component,
    initialState: () => {story: None, isLoading: false},
    didMount: loadComments,
    reducer: (action, state) =>
      switch (action) {
      | Loaded(story) => ReasonReact.Update({story, isLoading: false})
      | Loading => ReasonReact.Update({...state, isLoading: true})
      },
    render: self =>
      <SafeAreaView style=AppStyle.pageContainer>
        <View style=AppStyle.news>
          <CommentsFlatList data={self.state.story} />
        </View>
        /*
         * Footer && ActivityIndicator
         * TODO: Transparent bg
         */
        <View>
          {
            if (self.state.isLoading) {
              <ActivityIndicator
                style=AppStyle.activityIndicator
                size=`large
              />;
            } else {
              <View />;
            }
          }
        </View>
      </SafeAreaView>,
  };
};