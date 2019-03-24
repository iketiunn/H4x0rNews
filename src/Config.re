open BsReactNavigation;

type route =
  | News
  | Comments(int);
type navigationProp = SwitchNavigator.navigation(route);