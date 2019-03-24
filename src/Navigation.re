open BsReactNavigation;
/**
 * Stack lacks of binding,
 * and write binding is pain. (hard to test with yarn link and expo start)
 *
 * TODO: Better header style
 */
open Config;

module Stack =
  StackNavigator.Create({
    open StackNavigator;

    type route = Config.route;

    let initialRoute = News;
    let getScreen = (route, navigation) =>
      switch (route) {
      | News => (<NewsPage navigation />, screenOptions(~title="News", ()))
      | Comments(title, storyId) => (
          <CommentsPage storyId />,
          screenOptions(~title, ()),
        )
      };
  });

let render = Stack.render;