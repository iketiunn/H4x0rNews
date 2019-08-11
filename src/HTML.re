/*** TODO: first arg is event, need to get the right type */
[@bs.module "react-native-render-html"] [@react.component]
external make:
  (
    ~html: string,
    ~textSelectable: bool,
    ~onLinkPress: (string, string) => unit
  ) =>
  React.element =
  "default";