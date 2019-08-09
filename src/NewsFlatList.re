open BsReactNative;
open Share;

let component = ReasonReact.statelessComponent("NewsFlatList");
let commentImageSource =
  `Required(Packager.require("../assets/comment.png"));
let shareImageSource =
  `Required(Packager.require("../assets/share-button.png"));
let linkImageSource = `Required(Packager.require("../assets/link.png"));
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
          /* Share event */
          let sharePostLink = () => {
            /** Get the HN post url */
            let url =
              "https://news.ycombinator.com/item?id="
              ++ string_of_int(news.item.id);
            let content = `text(news.item.title ++ ": " ++ url ++ "\n");
            Js.Promise.(
              share(~content, ~dialogTitle="Share HN Link", ())
              |> then_(ret => resolve(ret))
              |> ignore
            );
          };
          let shareArticleLink = () => {
            /** Trans original HN post into valid url */
            let url =
              news.item.url
              |> Js.String.startsWith("http")
              |> (
                result =>
                  result ?
                    news.item.url :
                    "https://news.ycombinator.com/" ++ news.item.url
              );
            let content = `text(news.item.title ++ ": " ++ url ++ "\n");
            Js.Promise.(
              share(~content, ~dialogTitle="Share Article Link", ())
              |> then_(ret => resolve(ret))
              |> ignore
            );
          };

          /*
            React Native Linking opening new browser outside the app,
            Expo handle it better, when close the opened url it's more smooth.

            let openUrl = () => Linking.openURL(news.item.url) |> ignore;
           */
          <View style=AppStyle.NewsPage.listItemContainer>
            <View style=AppStyle.NewsPage.listIndex>
              <Text value=index style=AppStyle.NewsPage.listIndex />
              <Text value=point style=AppStyle.NewsPage.listIndex />
            </View>
            <View style=AppStyle.NewsPage.listContent>
              <Text
                value=title
                style=AppStyle.NewsPage.title
                onPress=openUrl
              />
              <Text value=domain style=AppStyle.NewsPage.domain />
              /***  */
              <View style=AppStyle.NewsPage.timeAgoAndUserAndLinkContainer>
                <Text
                  value=timeAgoAndUser
                  style=AppStyle.NewsPage.timeAgoAndUser
                />
                <TouchableOpacity onPress=shareArticleLink>
                  <Image
                    style=AppStyle.NewsPage.linkImage
                    source=linkImageSource
                  />
                </TouchableOpacity>
              </View>
            </View>
            <View style=AppStyle.NewsPage.commentAndShareContainer>
              <TouchableOpacity onPress=sharePostLink>
                <Image
                  style=AppStyle.NewsPage.shareImage
                  source=shareImageSource
                />
              </TouchableOpacity>
              <TouchableOpacity onPress=navigateToComment>
                <View style=AppStyle.NewsPage.commentContainer>
                  <Image
                    style=AppStyle.Common.image
                    source=commentImageSource
                  />
                  <Text
                    style=AppStyle.NewsPage.commentCount
                    value=commentsCount
                  />
                </View>
              </TouchableOpacity>
            </View>
          </View>;
        });
      /* Need to specified type! */
      let keyExtractor = (_item: Data.news, index) => string_of_int(index);
      let itemSeparatorComponent =
        FlatList.separatorComponent(_ =>
          <View style=AppStyle.NewsPage.separator />
        );
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