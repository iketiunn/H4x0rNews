open BsReactNative;
open Style;

let activityIndicator = style([backgroundColor(String("#F6F6EF"))]);
/*
 * Using it to handle notch
 */
let pageContainer =
  style([
    flex(1.0),
    backgroundColor(String("#FF6600")),
    paddingTop(
      Pt(
        Platform.os() == Platform.Android ?
          float_of_int(ReasonExpo.Constants.statusBarHeight) : 0.0,
      ),
    ),
  ]);
let news = style([flex(1.0), backgroundColor(String("#F6F6EF"))]);
let separator =
  style([
    height(Pt(1.0)),
    backgroundColor(String("#ededed")),
    marginTop(Pt(5.0)),
    marginBottom(Pt(5.0)),
  ]);

let listItemContainer =
  style([flex(1.0), flexWrap(Nowrap), flexDirection(Row)]);
let listIndex = style([flex(0.1), alignSelf(Center)]);
let listContent =
  style([flex(0.8), paddingLeft(Pt(5.0)), paddingRight(Pt(5.0))]);
let title = style([paddingTop(Pt(5.0)), fontWeight(`Bold)]);
let domain = style([fontStyle(Italic), color(String("#727270"))]);
let timeAgoAndUser = style([color(String("#727270"))]);
let listCommentAndFunc = style([flex(0.1), alignSelf(Center)]);