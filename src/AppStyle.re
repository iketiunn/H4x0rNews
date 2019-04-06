open BsReactNative;
open Style;

let hackerNewsHeaderBackgroundColor = backgroundColor(String("#FF6600"));
let hackerNewsContentBackgroundColor = backgroundColor(String("#F6F6EF"));
let grayColor = color(String("#727270"));

let activityIndicator = style([hackerNewsContentBackgroundColor]);
/*
 * Using it to handle notch
 */
let pageContainer =
  style([
    flex(1.0),
    hackerNewsHeaderBackgroundColor,
    overflow(Hidden),
    /*
     paddingTop(
       Pt(
         Platform.os() == Platform.Android ?
           float_of_int(ReasonExpo.Constants.statusBarHeight) : 0.0,
       ),
     ),
     */
  ]);

/** Common */
module Common = {
  let grayFontColor = style([grayColor]);
  let textCenter = style([textAlign(Center)]);

  let header = style([hackerNewsHeaderBackgroundColor]);
  let navigationTint = String("black");
};

/** News page */
let news = style([flex(1.0), hackerNewsContentBackgroundColor]);
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
let domain = style([fontStyle(Italic), grayColor]);
let timeAgoAndUser = Common.grayFontColor;
let listCommentAndFunc = style([flex(0.1), alignSelf(Center)]);

/** Comments page */;
module Comment = {
  let container = style([display(Flex), hackerNewsContentBackgroundColor]);
  let item = (level: int) => {
    let borderColor =
      switch (level mod 7) {
      | 0 => "#ff5252"
      | 1 => "#34ace0"
      | 2 => "#33d9b2"
      | 3 => "#ffda79"
      | 4 => "#ff793f"
      | 5 => "#ffb142"
      | 6 => "#40407a"
      | _ => "#84817a"
      };
    style([
      borderLeftColor(String(borderColor)),
      borderLeftWidth(3.0),
      paddingLeft(Pt(5.0)),
      marginTop(Pt(5.0)),
      hackerNewsContentBackgroundColor,
      /** For Android / iOS shadow */ elevation(2.0),
      shadowColor(String("#000000")),
      shadowOpacity(0.4),
      shadowRadius(1.0),
      shadowOffset(~height=1.0, ~width=0.0),
    ]);
  };
};

module CommentsPage = {
  let paddingLeft = style([paddingLeft(Pt(8.0))]);
};