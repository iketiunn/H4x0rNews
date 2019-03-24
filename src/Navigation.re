open BsReactNavigation;
/**
 * Stack is unusable due to lack of binding,
 * and write binding is pain. (hard to test with yarn link and expo start)
 */
open Config;

module Stack =
  SwitchNavigator.Create({
    open SwitchNavigator;

    type route = Config.route;

    let initialRoute = News;
    let getScreen = (route, navigation) =>
      switch (route) {
      | News => (<NewsPage navigation />, screenOptions())
      | Comments(storyId) => (
          <CommentsPage storyId navigation />,
          screenOptions(),
        )
      };
  });

let render = Stack.render;