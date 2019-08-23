open ReactNative;

let component = ReasonReact.statelessComponent("CommentsFlatList");
[@react.component]
let make = (~data: list(Data.comment), ()) => {
  let rec renderComment = (~comments: list(Data.comment), ~first) => {
    let renderItem =
        (comment: ReactNative.VirtualizedList.renderItemProps(Data.comment)) => {
      let item = comment##item;
      let user =
        switch (item.user) {
        | Some(u) => u
        | None => "[deleted]"
        };
      let userAndTimeAge = user ++ " " ++ item.time_ago;
      /*
       * NTH: Fold comment
       * Done: Better bottom
       */
      <View style=AppStyle.Comment.container>
        <View style={AppStyle.Comment.item(item.level)}>
          <Text style=AppStyle.Common.grayFontColor>
            userAndTimeAge->React.string
          </Text>
          <HtmlView content={item.content} />
        </View>
        {
          List.length(item.comments) > 0 ?
            renderComment(~comments=item.comments, ~first=false) : <View />
        }
      </View>;
    };
    let keyExtractor = (_item: Data.comment, index) => string_of_int(index);
    let listFooterComponent = () =>
      first ?
        <Text style=AppStyle.Common.textCenter>
          "End of the thread"->React.string
        </Text> :
        <View />;
    <FlatList
      data={Array.of_list(comments)}
      keyExtractor
      renderItem
      style=AppStyle.CommentsPage.paddingLeft
      _ListFooterComponent=listFooterComponent
    />;
  };
  ReactCompat.useRecordApi({
    ...component,
    render: _self =>
      if (List.length(data) > 0) {
        renderComment(~comments=data, ~first=true);
      } else {
        <View>
          <Text style=AppStyle.Common.textCenter>
            "No comments"->React.string
          </Text>
        </View>;
      },
  });
};