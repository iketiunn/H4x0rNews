open BsReactNavigation;

type route =
  | News
  | Comments(string, int);
type navigationProp = StackNavigator.navigation(route);