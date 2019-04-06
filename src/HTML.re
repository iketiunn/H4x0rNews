[@bs.module "react-native-render-html"]
external view: ReasonReact.reactClass = "default";

let make =
    (
      ~renderers=?,
      ~ignoredTags=?,
      ~ignoredStyles=?,
      ~allowedStyles=?,
      ~decodeEntities=?,
      ~debug=?,
      ~listsPrefixesRenderers=?,
      ~ignoreNodesFunction=?,
      ~alterData=?,
      ~alterChildren=?,
      ~alterNode=?,
      ~html: string,
      ~uri=?,
      ~tagsStyles=?,
      ~classesStyles=?,
      ~containerStyle=?,
      ~customWrapper=?,
      ~onLinkPress=?,
      ~onParsed=?,
      ~imagesMaxWidth=?,
      ~staticContentMaxWidth=?,
      ~imagesInitialDimensions=?,
      ~emSize=?,
      ~ptSize=?,
      ~baseFontStyle=?,
      ~textSelectable=?,
      ~renderersProps=?,
      ~allowFontScaling=?,
    ) =>
  ReasonReact.wrapJsForReason(
    ~reactClass=view,
    ~props={
      "renderers": renderers,
      "ignoredTags": ignoredTags,
      "ignoredStyles": ignoredStyles,
      "allowedStyles": allowedStyles,
      "decodeEntities": decodeEntities,
      "debug": debug,
      "listsPrefixesRenderers": listsPrefixesRenderers,
      "ignoreNodesFunction": ignoreNodesFunction,
      "alterData": alterData,
      "alterChildren": alterChildren,
      "alterNode": alterNode,
      "html": html,
      "uri": uri,
      "tagsStyles": tagsStyles,
      "classesStyles": classesStyles,
      "containerStyle": containerStyle,
      "customWrapper": customWrapper,
      "onLinkPress": onLinkPress,
      "onParsed": onParsed,
      "imagesMaxWidth": imagesMaxWidth,
      "staticContentMaxWidth": staticContentMaxWidth,
      "imagesInitialDimensions": imagesInitialDimensions,
      "emSize": emSize,
      "ptSize": ptSize,
      "baseFontStyle": baseFontStyle,
      "textSelectable": textSelectable,
      "renderersProps": renderersProps,
      "allowFontScaling": allowFontScaling,
    },
  );