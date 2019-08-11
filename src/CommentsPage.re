open ReactNative;
open ReactNavigation;

type state = {
  story: option(Data.story),
  isLoading: bool,
};
type action =
  | Loaded(Data.story)
  | Loading;
let component = ReasonReact.reducerComponent("Comments");
[@react.component]
let make = (~navigation) => {
  /** You will a optional param, not so Reasonable... */
  /** Not handle 0 */
  let storyId =
    navigation
    ->Navigation.getParam("storyId")
    ->Js.Nullable.toOption
    ->Belt.Option.mapWithDefault(0, id => id);
  let loadComments = ({ReasonReact.state, send}) =>
    if (!state.isLoading) {
      Js.Promise.(
        Data.fetchStory(string_of_int(storyId))
        |> then_(story => resolve(send(Loaded(story))))
        |> ignore
      );

      send(Loading);
    };
  ReactCompat.useRecordApi({
    ...component,
    initialState: () => {story: None, isLoading: false},
    didMount: loadComments,
    reducer: (action, state) =>
      switch (action) {
      | Loaded(story) =>
        ReasonReact.Update({story: Some(story), isLoading: false})
      | Loading => ReasonReact.Update({...state, isLoading: true})
      },
    render: self =>
      <SafeAreaView style=AppStyle.pageContainer>
        <View style=AppStyle.NewsPage.newsContainer>
          {
            switch (self.state.story) {
            | Some(story) =>
              let comments =
                switch (story.content) {
                | Some(_content) => [
                    Data.transStoryToComment(story),
                    ...story.comments,
                  ]
                | None => story.comments
                };
              <CommentsFlatList data=comments />;
            | None =>
              <View>
                {
                  if (self.state.isLoading) {
                    <ActivityIndicator
                      style=AppStyle.activityIndicator
                      size=ActivityIndicator.Size.large
                    />;
                  } else {
                    <View />;
                  }
                }
              </View>
            }
          }
        </View>
      </SafeAreaView>,
  });
};