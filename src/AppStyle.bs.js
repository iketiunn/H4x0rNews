// Generated by BUCKLESCRIPT VERSION 4.0.7, PLEASE EDIT WITH CARE
'use strict';

var Block = require("bs-platform/lib/js/block.js");
var Style$BsReactNative = require("bs-react-native/src/style.js");

var hackerNewsHeaderBackgroundColor = Style$BsReactNative.backgroundColor(/* String */Block.__(0, ["#FF6600"]));

var hackerNewsContentBackgroundColor = Style$BsReactNative.backgroundColor(/* String */Block.__(0, ["#F6F6EF"]));

var grayColor = Style$BsReactNative.color(/* String */Block.__(0, ["#727270"]));

var activityIndicator = Style$BsReactNative.style(/* :: */[
      hackerNewsContentBackgroundColor,
      /* [] */0
    ]);

var pageContainer = Style$BsReactNative.style(/* :: */[
      Style$BsReactNative.flex(1.0),
      /* :: */[
        hackerNewsHeaderBackgroundColor,
        /* :: */[
          Style$BsReactNative.overflow(/* Hidden */1),
          /* [] */0
        ]
      ]
    ]);

var grayFontColor = Style$BsReactNative.style(/* :: */[
      grayColor,
      /* [] */0
    ]);

var textCenter = Style$BsReactNative.style(/* :: */[
      Style$BsReactNative.textAlign(/* Center */3),
      /* [] */0
    ]);

var header = Style$BsReactNative.style(/* :: */[
      hackerNewsHeaderBackgroundColor,
      /* [] */0
    ]);

var Common_003 = /* navigationTint : String */["black"];

var Common = /* module */[
  /* grayFontColor */grayFontColor,
  /* textCenter */textCenter,
  /* header */header,
  Common_003
];

var news = Style$BsReactNative.style(/* :: */[
      Style$BsReactNative.flex(1.0),
      /* :: */[
        hackerNewsContentBackgroundColor,
        /* [] */0
      ]
    ]);

var separator = Style$BsReactNative.style(/* :: */[
      Style$BsReactNative.height(/* Pt */Block.__(0, [1.0])),
      /* :: */[
        Style$BsReactNative.backgroundColor(/* String */Block.__(0, ["#ededed"])),
        /* :: */[
          Style$BsReactNative.marginTop(/* Pt */Block.__(0, [5.0])),
          /* :: */[
            Style$BsReactNative.marginBottom(/* Pt */Block.__(0, [5.0])),
            /* [] */0
          ]
        ]
      ]
    ]);

var listItemContainer = Style$BsReactNative.style(/* :: */[
      Style$BsReactNative.display(/* Flex */0),
      /* :: */[
        Style$BsReactNative.flexWrap(/* Nowrap */1),
        /* :: */[
          Style$BsReactNative.flexDirection(/* Row */0),
          /* [] */0
        ]
      ]
    ]);

var listIndex = Style$BsReactNative.style(/* :: */[
      Style$BsReactNative.flex(0.125),
      /* :: */[
        Style$BsReactNative.alignSelf(/* Center */2),
        /* [] */0
      ]
    ]);

var listContent = Style$BsReactNative.style(/* :: */[
      Style$BsReactNative.flex(0.8),
      /* :: */[
        Style$BsReactNative.paddingLeft(/* Pt */Block.__(0, [5.0])),
        /* :: */[
          Style$BsReactNative.paddingRight(/* Pt */Block.__(0, [5.0])),
          /* [] */0
        ]
      ]
    ]);

var title = Style$BsReactNative.style(/* :: */[
      Style$BsReactNative.paddingTop(/* Pt */Block.__(0, [5.0])),
      /* :: */[
        Style$BsReactNative.fontWeight(/* Bold */737455525),
        /* [] */0
      ]
    ]);

var domain = Style$BsReactNative.style(/* :: */[
      Style$BsReactNative.fontStyle(/* Italic */1),
      /* :: */[
        grayColor,
        /* [] */0
      ]
    ]);

var inlineContainer = Style$BsReactNative.style(/* :: */[
      Style$BsReactNative.display(/* Flex */0),
      /* :: */[
        Style$BsReactNative.flexDirection(/* Row */0),
        /* :: */[
          Style$BsReactNative.justifyContent(/* SpaceBetween */5),
          /* [] */0
        ]
      ]
    ]);

var timeAgoAndUser = Style$BsReactNative.style(/* :: */[
      Style$BsReactNative.display(/* Flex */0),
      /* :: */[
        grayColor,
        /* [] */0
      ]
    ]);

var commentContainer = Style$BsReactNative.style(/* :: */[
      Style$BsReactNative.display(/* Flex */0),
      /* :: */[
        Style$BsReactNative.flexDirection(/* Row */0),
        /* :: */[
          Style$BsReactNative.alignItems(/* Center */2),
          /* [] */0
        ]
      ]
    ]);

var commentImage = Style$BsReactNative.style(/* :: */[
      Style$BsReactNative.width(/* Pt */Block.__(0, [15.0])),
      /* :: */[
        Style$BsReactNative.height(/* Pt */Block.__(0, [15.0])),
        /* [] */0
      ]
    ]);

var commentCount = Style$BsReactNative.style(/* :: */[
      Style$BsReactNative.paddingRight(/* Pt */Block.__(0, [3.0])),
      /* [] */0
    ]);

var listCommentAndFunc = Style$BsReactNative.style(/* :: */[
      Style$BsReactNative.flex(0.075),
      /* [] */0
    ]);

var container = Style$BsReactNative.style(/* :: */[
      Style$BsReactNative.display(/* Flex */0),
      /* :: */[
        hackerNewsContentBackgroundColor,
        /* [] */0
      ]
    ]);

function item(level) {
  var match = level % 7;
  var borderColor;
  switch (match) {
    case 0 : 
        borderColor = "#ff5252";
        break;
    case 1 : 
        borderColor = "#34ace0";
        break;
    case 2 : 
        borderColor = "#33d9b2";
        break;
    case 3 : 
        borderColor = "#ffda79";
        break;
    case 4 : 
        borderColor = "#ff793f";
        break;
    case 5 : 
        borderColor = "#ffb142";
        break;
    case 6 : 
        borderColor = "#40407a";
        break;
    default:
      borderColor = "#84817a";
  }
  return Style$BsReactNative.style(/* :: */[
              Style$BsReactNative.borderLeftColor(/* String */Block.__(0, [borderColor])),
              /* :: */[
                Style$BsReactNative.borderLeftWidth(3.0),
                /* :: */[
                  Style$BsReactNative.paddingLeft(/* Pt */Block.__(0, [5.0])),
                  /* :: */[
                    Style$BsReactNative.marginTop(/* Pt */Block.__(0, [5.0])),
                    /* :: */[
                      hackerNewsContentBackgroundColor,
                      /* :: */[
                        Style$BsReactNative.elevation(2.0),
                        /* :: */[
                          Style$BsReactNative.shadowColor(/* String */Block.__(0, ["#000000"])),
                          /* :: */[
                            Style$BsReactNative.shadowOpacity(0.4),
                            /* :: */[
                              Style$BsReactNative.shadowRadius(1.0),
                              /* :: */[
                                Style$BsReactNative.shadowOffset(1.0, 0.0),
                                /* [] */0
                              ]
                            ]
                          ]
                        ]
                      ]
                    ]
                  ]
                ]
              ]
            ]);
}

var Comment = /* module */[
  /* container */container,
  /* item */item
];

var paddingLeft = Style$BsReactNative.style(/* :: */[
      Style$BsReactNative.paddingLeft(/* Pt */Block.__(0, [8.0])),
      /* [] */0
    ]);

var CommentsPage = /* module */[/* paddingLeft */paddingLeft];

exports.hackerNewsHeaderBackgroundColor = hackerNewsHeaderBackgroundColor;
exports.hackerNewsContentBackgroundColor = hackerNewsContentBackgroundColor;
exports.grayColor = grayColor;
exports.activityIndicator = activityIndicator;
exports.pageContainer = pageContainer;
exports.Common = Common;
exports.news = news;
exports.separator = separator;
exports.listItemContainer = listItemContainer;
exports.listIndex = listIndex;
exports.listContent = listContent;
exports.title = title;
exports.domain = domain;
exports.inlineContainer = inlineContainer;
exports.timeAgoAndUser = timeAgoAndUser;
exports.commentContainer = commentContainer;
exports.commentImage = commentImage;
exports.commentCount = commentCount;
exports.listCommentAndFunc = listCommentAndFunc;
exports.Comment = Comment;
exports.CommentsPage = CommentsPage;
/* hackerNewsHeaderBackgroundColor Not a pure module */
