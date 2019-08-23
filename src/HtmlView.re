open ReactNative;

/**
 * Done: text select / sharing
 * Done: Link handle: was using a type-not-safe binding
 */
let onLinkPress = (_evt, href) => Linking.openURL(href) |> ignore;
let component = ReasonReact.statelessComponent("HtmlView");
[@react.component]
let make = (~content: string, ()) =>
  <View> <HTML html=content onLinkPress textSelectable=true /> </View>;