open BsReactNative;
open Style;

module RefreshButton = {
  let floatingActionButton =
    style([
      /*  Should get backgroundColor to cover the comments */
      backgroundColor(String("#F7F5F8")),
      borderStyle(Solid),
      borderColor(String("black")),
      width(Pt(40.0)),
      height(Pt(40.0)),
      borderRadius(100.0),
      position(Absolute),
      bottom(Pt(5.0)),
      right(Pt(20.0)),
      alignItems(Center),
      justifyContent(Center),
      /** For Android / iOS shadow */ elevation(2.0),
      shadowColor(String("#000000")),
      shadowOpacity(0.4),
      shadowRadius(1.0),
      shadowOffset(~height=1.0, ~width=0.0),
    ]);
};

let hackerNewsHeaderBackgroundColor = backgroundColor(String("#FF6600"));
let hackerNewsContentBackgroundColor = backgroundColor(String("#F6F6EF"));
let grayColor = color(String("#727270"));

let activityIndicator = style([hackerNewsContentBackgroundColor]);
/*
 * Using it to handle notch
 */
let pageContainer =
  style([flex(1.0), hackerNewsHeaderBackgroundColor, overflow(Hidden)]);

/** Common */
module Common = {
  let grayFontColor = style([grayColor]);
  let textCenter = style([textAlign(Center)]);

  let header = style([hackerNewsHeaderBackgroundColor]);
  let navigationTint = String("black");
  let imageHW = Pt(17.5);
  let imageSize = [width(imageHW), height(imageHW)];
  let image = style(imageSize);
};

module NewsPage = {
  open Common;
  let newsContainer = style([flex(1.0), hackerNewsContentBackgroundColor]);
  let separator =
    style([
      height(Pt(1.0)),
      backgroundColor(String("#ededed")),
      marginTop(Pt(5.0)),
      marginBottom(Pt(5.0)),
    ]);

  let listItemContainer =
    style([display(Flex), flexWrap(Nowrap), flexDirection(Row)]);
  let listIndex = style([flex(0.125), alignSelf(Center)]);
  let listContent =
    style([flex(0.740), paddingLeft(Pt(5.0)), paddingRight(Pt(5.0))]);
  let title = style([paddingTop(Pt(5.0)), fontWeight(`Bold)]);
  let domain = style([fontStyle(Italic), grayColor]);

  let timeAgoAndUserAndLinkContainer =
    style([
      display(Flex),
      flexDirection(Row),
      justifyContent(SpaceBetween),
    ]);

  let timeAgoAndUser = style([grayColor]);
  let commentAndShareContainer =
    style([
      flex(0.135),
      display(Flex),
      flexDirection(Column),
      justifyContent(SpaceBetween),
    ]);
  let commentContainer =
    style([display(Flex), flexDirection(Row), alignItems(Center)]);
  let linkImage = style([marginRight(Pt(5.0)), ...imageSize]);
  let shareImage = style([marginTop(Pt(12.0)), ...imageSize]);
  let commentCount = style([paddingLeft(Pt(3.0))]);
};

module Comment = {
  let container = style([display(Flex), hackerNewsContentBackgroundColor]);
  let item = (level: int) => {
    let marginTopVal = level == 0 ? 1.0 : 2.5;
    let borderColor =
      switch (level mod 7) {
      | (-1) => "#F6F6EF"
      | 0 => "#e74c3c"
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
      marginTop(Pt(marginTopVal)),
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