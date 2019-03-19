open BsReactNative;

let handleLink = url => ReasonExpo.WebBrowser.openBrowserAsync(url);
let component = ReasonReact.statelessComponent("NewsFlatList");
let make = (~data, _children) => {
  ...component,
  render: _self => {
    /* Need to specified type! */
    let renderItem =
      /* Make a card view */
      FlatList.renderItem((news: FlatList.renderBag(Data.news)) => {
        /* UI props */
        let index = string_of_int(news.index + 1);
        let pointInt =
          switch (news.item.points) {
          | Some(p) => p
          | None => 0
          };
        let point = string_of_int(pointInt) ++ "p";
        let title = news.item.title;
        let domain =
          switch (news.item.domain) {
          | Some(d) => "(" ++ d ++ ")"
          | None => ""
          };
        let user =
          switch (news.item.user) {
          | Some(u) => " by " ++ u
          | None => ""
          };
        let timeAgo = news.item.time_ago;
        let timeAgoAndUser = user ++ " " ++ timeAgo;
        let commentsCount = string_of_int(news.item.comments_count);
        /* Events */
        let openUrl = () =>
          ReasonExpo.WebBrowser.openBrowserAsync(news.item.url) |> ignore;

        <View style=AppStyle.listItemContainer>
          <View style=AppStyle.listIndex>
            <Text value=index style=AppStyle.listIndex />
            <Text value=point style=AppStyle.listIndex />
          </View>
          <View style=AppStyle.listContent>
            <Text value=title style=AppStyle.title onPress=openUrl />
            <Text value=domain style=AppStyle.domain />
            <Text value=timeAgoAndUser style=AppStyle.timeAgoAndUser />
          </View>
          <View style=AppStyle.listCommentAndFunc>
            <Text value=commentsCount />
          </View>
        </View>;
      });
    /* Need to specified type! */
    let keyExtractor = (item: Data.news, _index) => string_of_int(item.id);
    let itemSeparatorComponent =
      FlatList.separatorComponent(_ => <View style=AppStyle.separator />);
    <FlatList data keyExtractor renderItem itemSeparatorComponent />;
  },
};