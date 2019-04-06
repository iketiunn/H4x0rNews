open BsReactNavigation;
/**
 * Stack lacks of binding,
 * and write binding is pain. (hard to test with yarn link and expo start)
 *
 */
open Config;

module Stack =
  StackNavigator.Create({
    open StackNavigator;

    type route = Config.route;

    /*
     * To debugging comment style
     * let initialRoute = Comments("test", 19587782);
     *
     * Done: custom style the header, by adding binding in node_modules
     */
    let initialRoute = News;
    let getScreen = (route, navigation) =>
      switch (route) {
      | News => (
          <NewsPage navigation />,
          screenOptions(
            ~title="Top News",
            ~headerStyle=AppStyle.Common.header,
            (),
          ),
        )
      | Comments(title, storyId) => (
          <CommentsPage storyId />,
          screenOptions(~title, ~headerStyle=AppStyle.Common.header, ()),
        )
      };
  });

let render = Stack.render;