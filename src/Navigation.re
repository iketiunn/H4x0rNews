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

    /*
     * To debugging comment style
     * let initialRoute = News;
     */

    let initialRoute = Comments("test", 19587782);
    let getScreen = (route, navigation) =>
      switch (route) {
      | News => (<NewsPage navigation />, screenOptions(~title="News", ()))
      | Comments(title, storyId) => (
          <CommentsPage storyId />,
          screenOptions(),
        )
      };
  });

let render = Stack.render;