open BsReactNative;

let component = ReasonReact.statelessComponent("CommentsFlatList");
/**
 * story.comment[], may got a empty array
 */
let make = (~data: option(Data.story), _children) => {
  ...component,
  render: _self =>
    switch (data) {
    | Some(story) =>
      if (List.length(story.comments) > 0) {
        let renderItem =
          FlatList.renderItem((comment: FlatList.renderBag(Data.comment)) => {
            let user =
              switch (comment.item.user) {
              | Some(u) => u
              | None => ""
              };
            let userAndTimeAge = user ++ " " ++ comment.item.time_ago;
            /**
               TODO:
                 - Nest comment
                 - Better style
             */
            <View style=AppStyle.news>
              <Text value=userAndTimeAge />
              <ResizedWebView content={comment.item.content} />
            </View>;
          });
        let keyExtractor = (_item: Data.comment, index) =>
          string_of_int(index);
        let itemSeparatorComponent =
          FlatList.separatorComponent(_ => <View style=AppStyle.separator />);
        <FlatList
          data={Array.of_list(story.comments)}
          keyExtractor
          renderItem
          itemSeparatorComponent
        />;
      } else {
        <View> <Text value="No comment!" /> </View>;
      }
    | None => <View> <Text value="Loading..." /> </View>
    },
};