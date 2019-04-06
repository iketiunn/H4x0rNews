open BsReactNative;

let component = ReasonReact.statelessComponent("CommentsFlatList");
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
        let padding = float_of_int(comment.item.level * 1);
        /*
           TODO:
             - Better style
         */
        <View
          style={
            Style.style([
              Style.paddingLeft(Style.Pt(padding)),
              Style.flex(1.0),
              Style.backgroundColor(String("#F6F6EF")),
            ])
          }>
          <Text value=userAndTimeAge />
          <HtmlView content={comment.item.content} />
          {
            List.length(comment.item.comments) > 0 ?
              renderComment(comment.item.comments) : <View />
          }
        </View>;
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
        <View> <Text value="End ot the thread" /> </View>;
      },
  };
};