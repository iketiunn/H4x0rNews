// Generated by BUCKLESCRIPT VERSION 4.0.7, PLEASE EDIT WITH CARE
'use strict';

var Curry = require("bs-platform/lib/js/curry.js");
var AppStyle = require("./AppStyle.bs.js");
var ReasonReact = require("reason-react/src/ReasonReact.js");
var Js_primitive = require("bs-platform/lib/js/js_primitive.js");
var Text$BsReactNative = require("bs-react-native/src/components/text.js");
var View$BsReactNative = require("bs-react-native/src/components/view.js");
var Image$BsReactNative = require("bs-react-native/src/components/image.js");
var Share$BsReactNative = require("bs-react-native/src/share.js");
var WebBrowser$ReasonExpo = require("reason-expo/src/WebBrowser.bs.js");
var FlatList$BsReactNative = require("bs-react-native/src/components/flatList.js");
var TouchableOpacity$BsReactNative = require("bs-react-native/src/components/touchableOpacity.js");

var component = ReasonReact.statelessComponent("NewsFlatList");

var commentImageSource_001 = require("../assets/comment.png");

var commentImageSource = /* `Required */[
  202657151,
  commentImageSource_001
];

var shareImageSource_001 = require("../assets/share-button.png");

var shareImageSource = /* `Required */[
  202657151,
  shareImageSource_001
];

var linkImageSource_001 = require("../assets/link.png");

var linkImageSource = /* `Required */[
  202657151,
  linkImageSource_001
];

function make(data, refreshing, onRefresh, onEndReached, navigation, _children) {
  return /* record */[
          /* debugName */component[/* debugName */0],
          /* reactClassInternal */component[/* reactClassInternal */1],
          /* handedOffState */component[/* handedOffState */2],
          /* willReceiveProps */component[/* willReceiveProps */3],
          /* didMount */component[/* didMount */4],
          /* didUpdate */component[/* didUpdate */5],
          /* willUnmount */component[/* willUnmount */6],
          /* willUpdate */component[/* willUpdate */7],
          /* shouldUpdate */component[/* shouldUpdate */8],
          /* render */(function (_self) {
              var renderItem = function (param) {
                return FlatList$BsReactNative.renderItem((function (news) {
                              var index = String(news[/* index */1] + 1 | 0);
                              var match = news[/* item */0][/* points */2];
                              var pointInt = match !== undefined ? match : 0;
                              var point = String(pointInt) + "p";
                              var title = news[/* item */0][/* title */1];
                              var match$1 = news[/* item */0][/* domain */9];
                              var domain = match$1 !== undefined ? match$1 : "";
                              var match$2 = news[/* item */0][/* user */3];
                              var user = match$2 !== undefined ? "by " + match$2 : "";
                              var timeAgo = news[/* item */0][/* time_ago */5];
                              var timeAgoAndUser = user + (" " + timeAgo);
                              var commentsCount = String(news[/* item */0][/* comments_count */6]);
                              var navigateToComment = function (param) {
                                return Curry._1(navigation[/* push */0], /* Comments */[
                                            title,
                                            news[/* item */0][/* id */0]
                                          ]);
                              };
                              var openUrl = function (param) {
                                var match = domain === "";
                                if (match) {
                                  return Curry._1(navigation[/* push */0], /* Comments */[
                                              title,
                                              news[/* item */0][/* id */0]
                                            ]);
                                } else {
                                  WebBrowser$ReasonExpo.openBrowserAsync(news[/* item */0][/* url */8]);
                                  return /* () */0;
                                }
                              };
                              var sharePostLink = function (param) {
                                var url = "https://news.ycombinator.com/item?id=" + String(news[/* item */0][/* id */0]);
                                var content_001 = news[/* item */0][/* title */1] + (": " + (url + "\n"));
                                var content = /* `text */[
                                  -856044371,
                                  content_001
                                ];
                                Share$BsReactNative.share(content, undefined, undefined, undefined, undefined, "Share HN Link", /* () */0).then((function (ret) {
                                        return Promise.resolve(ret);
                                      }));
                                return /* () */0;
                              };
                              var shareArticleLink = function (param) {
                                var result = news[/* item */0][/* url */8].startsWith("http");
                                var url = result ? news[/* item */0][/* url */8] : "https://news.ycombinator.com/" + news[/* item */0][/* url */8];
                                var content_001 = news[/* item */0][/* title */1] + (": " + (url + "\n"));
                                var content = /* `text */[
                                  -856044371,
                                  content_001
                                ];
                                Share$BsReactNative.share(content, undefined, undefined, undefined, undefined, "Share Article Link", /* () */0).then((function (ret) {
                                        return Promise.resolve(ret);
                                      }));
                                return /* () */0;
                              };
                              return ReasonReact.element(undefined, undefined, View$BsReactNative.make(undefined, undefined, undefined, undefined, undefined, undefined, undefined, undefined, undefined, Js_primitive.some(AppStyle.NewsPage[/* listItemContainer */2]), undefined, undefined, undefined, undefined, undefined, undefined, undefined, undefined, undefined, undefined)(/* array */[
                                              ReasonReact.element(undefined, undefined, View$BsReactNative.make(undefined, undefined, undefined, undefined, undefined, undefined, undefined, undefined, undefined, Js_primitive.some(AppStyle.NewsPage[/* listIndex */3]), undefined, undefined, undefined, undefined, undefined, undefined, undefined, undefined, undefined, undefined)(/* array */[
                                                        ReasonReact.element(undefined, undefined, Text$BsReactNative.make(undefined, undefined, undefined, undefined, undefined, undefined, undefined, undefined, undefined, Js_primitive.some(AppStyle.NewsPage[/* listIndex */3]), undefined, undefined, undefined, undefined, undefined, undefined, index, /* array */[])),
                                                        ReasonReact.element(undefined, undefined, Text$BsReactNative.make(undefined, undefined, undefined, undefined, undefined, undefined, undefined, undefined, undefined, Js_primitive.some(AppStyle.NewsPage[/* listIndex */3]), undefined, undefined, undefined, undefined, undefined, undefined, point, /* array */[]))
                                                      ])),
                                              ReasonReact.element(undefined, undefined, View$BsReactNative.make(undefined, undefined, undefined, undefined, undefined, undefined, undefined, undefined, undefined, Js_primitive.some(AppStyle.NewsPage[/* listContent */4]), undefined, undefined, undefined, undefined, undefined, undefined, undefined, undefined, undefined, undefined)(/* array */[
                                                        ReasonReact.element(undefined, undefined, Text$BsReactNative.make(undefined, undefined, undefined, undefined, undefined, undefined, openUrl, undefined, undefined, Js_primitive.some(AppStyle.NewsPage[/* title */5]), undefined, undefined, undefined, undefined, undefined, undefined, title, /* array */[])),
                                                        ReasonReact.element(undefined, undefined, Text$BsReactNative.make(undefined, undefined, undefined, undefined, undefined, undefined, undefined, undefined, undefined, Js_primitive.some(AppStyle.NewsPage[/* domain */6]), undefined, undefined, undefined, undefined, undefined, undefined, domain, /* array */[])),
                                                        ReasonReact.element(undefined, undefined, View$BsReactNative.make(undefined, undefined, undefined, undefined, undefined, undefined, undefined, undefined, undefined, Js_primitive.some(AppStyle.NewsPage[/* timeAgoAndUserAndLinkContainer */7]), undefined, undefined, undefined, undefined, undefined, undefined, undefined, undefined, undefined, undefined)(/* array */[
                                                                  ReasonReact.element(undefined, undefined, Text$BsReactNative.make(undefined, undefined, undefined, undefined, undefined, undefined, undefined, undefined, undefined, Js_primitive.some(AppStyle.NewsPage[/* timeAgoAndUser */8]), undefined, undefined, undefined, undefined, undefined, undefined, timeAgoAndUser, /* array */[])),
                                                                  ReasonReact.element(undefined, undefined, TouchableOpacity$BsReactNative.make(undefined, undefined, undefined, undefined, undefined, undefined, undefined, undefined, undefined, undefined, undefined, shareArticleLink, undefined, undefined, undefined, undefined, undefined, undefined, undefined)(/* array */[ReasonReact.element(undefined, undefined, Image$BsReactNative.make(undefined, undefined, undefined, undefined, undefined, undefined, linkImageSource, Js_primitive.some(AppStyle.NewsPage[/* linkImage */11]), undefined, undefined, undefined, undefined, undefined, undefined, undefined, undefined, undefined)(/* array */[]))]))
                                                                ]))
                                                      ])),
                                              ReasonReact.element(undefined, undefined, View$BsReactNative.make(undefined, undefined, undefined, undefined, undefined, undefined, undefined, undefined, undefined, Js_primitive.some(AppStyle.NewsPage[/* commentAndShareContainer */9]), undefined, undefined, undefined, undefined, undefined, undefined, undefined, undefined, undefined, undefined)(/* array */[
                                                        ReasonReact.element(undefined, undefined, TouchableOpacity$BsReactNative.make(undefined, undefined, undefined, undefined, undefined, undefined, undefined, undefined, undefined, undefined, undefined, sharePostLink, undefined, undefined, undefined, undefined, undefined, undefined, undefined)(/* array */[ReasonReact.element(undefined, undefined, Image$BsReactNative.make(undefined, undefined, undefined, undefined, undefined, undefined, shareImageSource, Js_primitive.some(AppStyle.NewsPage[/* shareImage */12]), undefined, undefined, undefined, undefined, undefined, undefined, undefined, undefined, undefined)(/* array */[]))])),
                                                        ReasonReact.element(undefined, undefined, TouchableOpacity$BsReactNative.make(undefined, undefined, undefined, undefined, undefined, undefined, undefined, undefined, undefined, undefined, undefined, navigateToComment, undefined, undefined, undefined, undefined, undefined, undefined, undefined)(/* array */[ReasonReact.element(undefined, undefined, View$BsReactNative.make(undefined, undefined, undefined, undefined, undefined, undefined, undefined, undefined, undefined, Js_primitive.some(AppStyle.NewsPage[/* commentContainer */10]), undefined, undefined, undefined, undefined, undefined, undefined, undefined, undefined, undefined, undefined)(/* array */[
                                                                            ReasonReact.element(undefined, undefined, Image$BsReactNative.make(undefined, undefined, undefined, undefined, undefined, undefined, commentImageSource, Js_primitive.some(AppStyle.Common[/* image */6]), undefined, undefined, undefined, undefined, undefined, undefined, undefined, undefined, undefined)(/* array */[])),
                                                                            ReasonReact.element(undefined, undefined, Text$BsReactNative.make(undefined, undefined, undefined, undefined, undefined, undefined, undefined, undefined, undefined, Js_primitive.some(AppStyle.NewsPage[/* commentCount */13]), undefined, undefined, undefined, undefined, undefined, undefined, commentsCount, /* array */[]))
                                                                          ]))]))
                                                      ]))
                                            ]));
                            }), param);
              };
              var keyExtractor = function (_item, index) {
                return String(index);
              };
              var itemSeparatorComponent = function (param) {
                return FlatList$BsReactNative.separatorComponent((function (param) {
                              return ReasonReact.element(undefined, undefined, View$BsReactNative.make(undefined, undefined, undefined, undefined, undefined, undefined, undefined, undefined, undefined, Js_primitive.some(AppStyle.NewsPage[/* separator */1]), undefined, undefined, undefined, undefined, undefined, undefined, undefined, undefined, undefined, undefined)(/* array */[]));
                            }), param);
              };
              return ReasonReact.element(undefined, undefined, FlatList$BsReactNative.make(data, renderItem, keyExtractor, Js_primitive.some(itemSeparatorComponent), undefined, undefined, undefined, undefined, undefined, undefined, undefined, undefined, undefined, undefined, undefined, onEndReached, 0.5, onRefresh, undefined, undefined, undefined, refreshing, undefined, undefined, undefined, undefined, undefined, undefined, undefined, undefined, undefined)(/* array */[]));
            }),
          /* initialState */component[/* initialState */10],
          /* retainedProps */component[/* retainedProps */11],
          /* reducer */component[/* reducer */12],
          /* jsElementWrapped */component[/* jsElementWrapped */13]
        ];
}

exports.component = component;
exports.commentImageSource = commentImageSource;
exports.shareImageSource = shareImageSource;
exports.linkImageSource = linkImageSource;
exports.make = make;
/* component Not a pure module */
