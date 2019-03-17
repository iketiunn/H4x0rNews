open BsReactNative;
open Style;

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