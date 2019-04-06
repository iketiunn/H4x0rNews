open BsReactNative;

let component = ReasonReact.statelessComponent("CommentsFlatList");
let make = (~data: list(Data.comment), _children) => {
  let rec renderComment = (comments: list(Data.comment)) => {
    let renderItem =
      FlatList.renderItem((comment: FlatList.renderBag(Data.comment)) => {
        let user =
          switch (comment.item.user) {
          | Some(u) => u
          | None => "[deleted]"
          };
        let userAndTimeAge = user ++ " " ++ comment.item.time_ago;
        /*
           TODO:
             - Fold comment
         */
        <View style=AppStyle.Comment.container>
          <View style={AppStyle.Comment.item(comment.item.level)}>
            <Text style=AppStyle.Common.grayFontColor value=userAndTimeAge />
            <HtmlView content={comment.item.content} />
          </View>
          {
            List.length(comment.item.comments) > 0 ?
              renderComment(comment.item.comments) : <View />
          }
        </View>;
      });
    let keyExtractor = (_item: Data.comment, index) => string_of_int(index);
    <FlatList
      data={Array.of_list(comments)}
      keyExtractor
      renderItem
      style=AppStyle.CommentsPage.paddingLeft
    />;
  };
  {
    ...component,
    render: _self =>
      if (List.length(data) > 0) {
        renderComment(data);
      } else {
        <View> <Text value="End ot the thread" /> </View>;
      },
  };
};