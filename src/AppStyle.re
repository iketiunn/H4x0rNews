open ReactNative;

module RefreshButton = {
  let floatingActionButton =
    Style.(
      style(
        ~backgroundColor="#F7F5F8",
        ~borderStyle=`solid,
        ~borderColor="black",
        ~width=40.0->dp,
        ~height=40.0->dp,
        ~borderRadius=100.0,
        ~position=`absolute,
        ~bottom=5.0->dp,
        ~right=20.0->dp,
        ~alignItems=`center,
        ~justifyContent=`center,
        ~shadowColor="#000000",
        ~shadowOpacity=0.4,
        ~shadowRadius=1.0,
        ~shadowOffset=offset(~height=1.0, ~width=0.0),
        (),
      )
    );
};

let hackerNewsHeaderBackgroundColor =
  Style.(style(~backgroundColor="#FF6600", ()));
let hackerNewsContentBackgroundColor =
  Style.(style(~backgroundColor="#F6F6EF", ()));
let grayColor = Style.(style(~color="#727270", ()));

/* let activityIndicator = style([hackerNewsContentBackgroundColor]); */
let activityIndicator = hackerNewsContentBackgroundColor;
/*
 * Using it to handle notch
 */
/* let pageContainer =
   style([flex(1.0), hackerNewsHeaderBackgroundColor, overflow(Hidden)]); */
let pageContainer =
  Style.(
    array([|
      hackerNewsHeaderBackgroundColor,
      style(~flex=1.0, ~overflow=`hidden, ()),
    |])
  );

/** Common */
module Common = {
  let grayFontColor = grayColor;
  let textCenter = Style.(style(~textAlign=`center, ()));

  let header = hackerNewsHeaderBackgroundColor;
  let navigationTint = "black";
  let imageHW = 17.5->Style.dp;
  /* let imageSize = [width(imageHW), height(imageHW)]; */
  let imageSize = Style.(style(~width=imageHW, ~height=imageHW, ()));
  let image = imageSize;
};

module NewsPage = {
  open Common;
  let newsContainer =
    Style.(
      array([|hackerNewsContentBackgroundColor, style(~flex=1.0, ())|])
    );
  let separator =
    Style.(
      style(
        ~height=1.0->dp,
        ~backgroundColor="#ededed",
        ~marginTop=5.0->dp,
        ~marginBottom=5.0->dp,
        (),
      )
    );
  let listItemContainer =
    Style.(style(~display=`flex, ~flexWrap=`nowrap, ~flexDirection=`row, ()));
  let listIndex = Style.(style(~flex=0.125, ~alignSelf=`center, ()));
  let listContent =
    Style.(
      style(~flex=0.740, ~paddingLeft=5.0->dp, ~paddingRight=5.0->dp, ())
    );
  let title = Style.(style(~paddingTop=5.0->dp, ~fontWeight=`bold, ()));
  let domain =
    Style.(array([|grayColor, style(~flex=1.0, ~overflow=`hidden, ())|]));

  let timeAgoAndUserAndLinkContainer =
    Style.(
      style(
        ~display=`flex,
        ~flexDirection=`row,
        ~justifyContent=`spaceBetween,
        (),
      )
    );

  let timeAgoAndUser = grayColor;
  let commentAndShareContainer =
    Style.(
      style(
        ~flex=0.135,
        ~display=`flex,
        ~flexDirection=`column,
        ~justifyContent=`spaceBetween,
        (),
      )
    );
  let commentContainer =
    Style.(
      style(~display=`flex, ~flexDirection=`row, ~alignItems=`center, ())
    );
  let linkImage =
    Style.(array([|style(~marginRight=5.0->dp, ()), imageSize|]));
  let shareImage =
    Style.(array([|style(~marginTop=12.0->dp, ()), imageSize|]));
  let commentCount = Style.(style(~paddingLeft=3.0->dp, ()));
};

module Comment = {
  /* let container = style([display(Flex), hackerNewsContentBackgroundColor]); */
  let container =
    Style.(
      array([|
        /* style(~display=`flex, ~marginBottom=1.5->dp, ()), */
        style(~display=`flex, ~marginTop=1.5->dp, ~marginBottom=1.0->dp, ()),
        hackerNewsContentBackgroundColor,
      |])
    );
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
    Style.(
      array([|
        style(
          ~borderLeftColor=borderColor,
          ~borderLeftWidth=3.0,
          ~paddingLeft=5.0->dp,
          ~marginTop=marginTopVal->dp,
          ~elevation=2.0,
          ~shadowColor="#000000",
          ~shadowOpacity=0.4,
          ~shadowRadius=1.0,
          ~shadowOffset=offset(~height=1.0, ~width=0.0),
          (),
        ),
        hackerNewsContentBackgroundColor,
      |])
    );
  };
};
module CommentsPage = {
  let paddingLeft = Style.(style(~paddingLeft=8.0->dp, ()));
};