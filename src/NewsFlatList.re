open ReactNative;
open ReactNavigation;
open Share;
open Image;

let component = ReasonReact.statelessComponent("NewsFlatList");
let commentImageSource =
  Source.fromRequired(Packager.require("../assets/comment.png"));
let shareImageSource =
  Source.fromRequired(Packager.require("../assets/share-button.png"));
let linkImageSource =
  Source.fromRequired(Packager.require("../assets/link.png"));
[@react.component]
let make =
    (
      ~data,
      ~refreshing,
      ~onRefresh,
      ~onEndReached,
      ~navigation: Navigation.t,
      (),
    ) =>
  /* ~ref, */
  ReactCompat.useRecordApi({
    ...component,
    render: _self => {
      /* Need to specified type! */
      let renderItem =
          /* Make a card view */
          (news: ReactNative.VirtualizedList.renderItemProps(Data.news)) => {
        /* UI props */
        let index = string_of_int(news##index + 1);
        let pointInt =
          switch (news##item.points) {
          | Some(p) => p
          | None => 0
          };
        let point = string_of_int(pointInt) ++ "p";
        let title = news##item.title;
        let domain =
          switch (news##item.domain) {
          | Some(d) => d
          | None => ""
          };
        let user =
          switch (news##item.user) {
          | Some(u) => "by " ++ u
          | None => ""
          };
        let timeAgo = news##item.time_ago;
        let timeAgoAndUser = user ++ " " ++ timeAgo;
        let commentsCount = string_of_int(news##item.comments_count);
        let navigateToComment = _e =>
          navigation
          ->Navigation.navigateWithParams(
              "Comments",
              {"title": title, "storyId": news##item.id},
            );
        /* Events */
        let openUrl = () =>
          domain === "" ?
            navigateToComment() : Linking.openURL(news##item.url) |> ignore;
        /* Share event */
        let sharePostLink = _e => {
          /** Get the HN post url */
          let url =
            "https://news.ycombinator.com/item?id="
            ++ string_of_int(news##item.id);
          let content =
            content(
              ~message=news##item.title ++ ": " ++ url ++ "\n",
              ~url,
              (),
            );
          Js.Promise.(
            shareWithOptions(
              content,
              options(~dialogTitle="Share HN Link", ()),
            )
            |> then_(ret => resolve(ret))
            |> ignore
          );
        };
        let shareArticleLink = _e => {
          /** Trans original HN post into valid url */
          let url =
            news##item.url
            |> Js.String.startsWith("http")
            |> (
              result =>
                result ?
                  news##item.url :
                  "https://news.ycombinator.com/" ++ news##item.url
            );
          let content =
            content(
              ~message=news##item.title ++ ": " ++ url ++ "\n",
              ~url,
              (),
            );
          Js.Promise.(
            shareWithOptions(
              content,
              options(~dialogTitle="Share Article Link", ()),
            )
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
            <Text style=AppStyle.NewsPage.listIndex>
              index->React.string
            </Text>
            <Text style=AppStyle.NewsPage.listIndex>
              point->React.string
            </Text>
          </View>
          <View style=AppStyle.NewsPage.listContent>
            <Text style=AppStyle.NewsPage.title onPress=openUrl>
              title->React.string
            </Text>
            <Text style=AppStyle.NewsPage.domain> domain->React.string </Text>
            <View style=AppStyle.NewsPage.timeAgoAndUserAndLinkContainer>
              <Text style=AppStyle.NewsPage.timeAgoAndUser>
                timeAgoAndUser->React.string
              </Text>
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
                <Image style=AppStyle.Common.image source=commentImageSource />
                <Text style=AppStyle.NewsPage.commentCount>
                  commentsCount->React.string
                </Text>
              </View>
            </TouchableOpacity>
          </View>
        </View>;
      };
      /* Need to specified type! */
      let keyExtractor = (_item: Data.news, index) => string_of_int(index);
      let itemSeparatorComponent = _props =>
        <View style=AppStyle.NewsPage.separator />;

      /** Not support ~ref to do scrollToIndex */
      <FlatList
        data
        refreshing
        onRefresh
        keyExtractor
        renderItem
        _ItemSeparatorComponent=itemSeparatorComponent
        onEndReached
        onEndReachedThreshold=0.5
      />;
    },
  });