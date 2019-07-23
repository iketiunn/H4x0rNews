open BsReactNative;

let component = ReasonReact.statelessComponent("NewsFlatList");
let commentImageSource =
  `Required(Packager.require("../assets/comment.png"));
let make =
    (
      ~data,
      ~refreshing,
      ~onRefresh,
      ~onEndReached,
      ~navigation: Config.navigationProp,
      _children,
    ) =>
  /* ~ref, */
  {
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
            | Some(d) => d
            | None => ""
            };
          let user =
            switch (news.item.user) {
            | Some(u) => "by " ++ u
            | None => ""
            };
          let timeAgo = news.item.time_ago;
          let timeAgoAndUser = user ++ " " ++ timeAgo;
          let commentsCount = string_of_int(news.item.comments_count);
          let navigateToComment = () =>
            navigation.push(Comments(title, news.item.id));
          /* Events */
          let openUrl = () =>
            domain === "" ?
              navigation.push(Comments(title, news.item.id)) :
              /* Linking.openURL(news.item.url) |> ignore; */
              ReasonExpo.WebBrowser.openBrowserAsync(news.item.url) |> ignore;

          /*
            React Native Linking opening new borwser outside the app,
            Expo handle it better, when close the opened url it's more smooth.

            let openUrl = () => Linking.openURL(news.item.url) |> ignore;
           */
          <View style=AppStyle.listItemContainer>
            <View style=AppStyle.listIndex>
              <Text value=index style=AppStyle.listIndex />
              <Text value=point style=AppStyle.listIndex />
            </View>
            <View style=AppStyle.listContent>
              <Text value=title style=AppStyle.title onPress=openUrl />
              <Text value=domain style=AppStyle.domain />
              <View style=AppStyle.inlineContainer>
                <Text value=timeAgoAndUser style=AppStyle.timeAgoAndUser />
                /* TODO: onPress */
                <View style=AppStyle.commentContainer>
                  <Text
                    style=AppStyle.commentCount
                    value=commentsCount
                    onPress=navigateToComment
                  />
                  <Image
                    style=AppStyle.commentImage
                    source=commentImageSource
                  />
                </View>
              </View>
            </View>
            <View style=AppStyle.listCommentAndFunc>
              <Text value="..." />
            </View>
          </View>;
        });
      /* Need to specified type! */
      let keyExtractor = (_item: Data.news, index) => string_of_int(index);
      let itemSeparatorComponent =
        FlatList.separatorComponent(_ => <View style=AppStyle.separator />);
      /** Not support ~ref to do scrollToIndex */
      <FlatList
        data
        refreshing
        onRefresh
        keyExtractor
        renderItem
        itemSeparatorComponent
        onEndReached
        onEndReachedThreshold=0.5
      />;
    },
  };