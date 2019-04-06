open BsReactNative;

/**
 * TODO:
 * - Better style, code block
 * - Link handle
 */
let component = ReasonReact.statelessComponent("HtmlView");
let make = (~content: string, _children) => {
  ...component,
  render: _self => <View> <HTML html=content /> </View>,
};