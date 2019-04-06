open BsReactNative;

/**
 * TODO:
 * - Better, preferment render component
 * - Handle webview link
 * - Laggy when list got more than 50 on android
 */
let screenWidth = Dimensions.get(`window)##width;
type state = {webViewHeight: float};
type action =
  | Loaded(float);
let component = ReasonReact.reducerComponent("ResizedWebView");
let make = (~content: string, _children) => {
  ...component,
  initialState: () => {webViewHeight: 0.0},
  reducer: (action, _state) =>
    switch (action) {
    | Loaded(height) => ReasonReact.Update({webViewHeight: height})
    },
  render: _self => <View> <HTML html=content /> </View>,
};