open BsReactNative;

let component = ReasonReact.statelessComponent("CommentsFlatList");
/**
 * story.comment[], may got a empty array
 */
let make = (~data: list(Data.comment), _children) => {
  let rec renderComment = (comments: list(Data.comment)) => {
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
                 - Better style
             */
        <View style=AppStyle.news>
          <Text value=userAndTimeAge />
          <ResizedWebView content={comment.item.content} />
          {
            List.length(comment.item.comments) > 0 ?
              renderComment(comment.item.comments) : <View />
          }
        </View>;
        /* Next level comment */
      });
    let keyExtractor = (_item: Data.comment, index) => string_of_int(index);
    let itemSeparatorComponent =
      FlatList.separatorComponent(_ => <View style=AppStyle.separator />);
    <FlatList
      data={Array.of_list(comments)}
      keyExtractor
      renderItem
      itemSeparatorComponent
    />;
  };
  {
    ...component,
    render: _self =>
      if (List.length(data) > 0) {
        renderComment(data);
      } else {
        <View> <Text value="Loding..." /> </View>;
      },
  };
};