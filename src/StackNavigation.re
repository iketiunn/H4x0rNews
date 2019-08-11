open ReactNavigation;

module AppContainer =
  AppContainer.Make({
    type screenProps = {. "someProp": int};

    let navigator =
      StackNavigator.make({
        "News": {
          screen: NewsPage.make,
          navigationOptions: () => {
            title: "Top News",
            headerStyle: AppStyle.hackerNewsHeaderBackgroundColor,
          },
        },
        "Comments": {
          screen: CommentsPage.make,
          navigationOptions: (options: {. navigation: Navigation.t}) => {
            let navigation = options##navigation;
            let title =
              navigation
              ->Navigation.getParam("title")
              ->Js.Nullable.toOption
              ->Belt.Option.mapWithDefault("Comments", t => t);

            {title, headerStyle: AppStyle.hackerNewsHeaderBackgroundColor};
          },
        },
      });
  });

[@react.component]
let make = () => <AppContainer />;