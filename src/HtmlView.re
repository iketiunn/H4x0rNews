open BsReactNative;

/**
 * Done: text select / sharing
 * Done: Link handle: was using a type-not-safe binding
 */
let onLinkPress = (_evt, href) =>
  /* Linking.openURL(href) |> ignore; */
  ReasonExpo.WebBrowser.openBrowserAsync(href) |> ignore;
let component = ReasonReact.statelessComponent("HtmlView");
let make = (~content: string, _children) => {
  ...component,
  render: _self =>
    <View> <HTML html=content onLinkPress textSelectable=true /> </View>,
};