// Generated by BUCKLESCRIPT VERSION 4.0.7, PLEASE EDIT WITH CARE
'use strict';

var Curry = require("bs-platform/lib/js/curry.js");
var AppStyle = require("./AppStyle.bs.js");
var ReasonReact = require("reason-react/src/ReasonReact.js");
var Js_primitive = require("bs-platform/lib/js/js_primitive.js");
var Text$BsReactNative = require("bs-react-native/src/components/text.js");
var View$BsReactNative = require("bs-react-native/src/components/view.js");
var WebBrowser$ReasonExpo = require("reason-expo/src/WebBrowser.bs.js");
var FlatList$BsReactNative = require("bs-react-native/src/components/flatList.js");

var component = ReasonReact.statelessComponent("NewsFlatList");

function make(data, onEndReached, navigation, _children) {
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
                              var domain = match$1 !== undefined ? "(" + (match$1 + ")") : "";
                              var match$2 = news[/* item */0][/* user */3];
                              var user = match$2 !== undefined ? " by " + match$2 : "";
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
                              return ReasonReact.element(undefined, undefined, View$BsReactNative.make(undefined, undefined, undefined, undefined, undefined, undefined, undefined, undefined, undefined, Js_primitive.some(AppStyle.listItemContainer), undefined, undefined, undefined, undefined, undefined, undefined, undefined, undefined, undefined, undefined)(/* array */[
                                              ReasonReact.element(undefined, undefined, View$BsReactNative.make(undefined, undefined, undefined, undefined, undefined, undefined, undefined, undefined, undefined, Js_primitive.some(AppStyle.listIndex), undefined, undefined, undefined, undefined, undefined, undefined, undefined, undefined, undefined, undefined)(/* array */[
                                                        ReasonReact.element(undefined, undefined, Text$BsReactNative.make(undefined, undefined, undefined, undefined, undefined, undefined, undefined, undefined, undefined, Js_primitive.some(AppStyle.listIndex), undefined, undefined, undefined, undefined, undefined, undefined, index, /* array */[])),
                                                        ReasonReact.element(undefined, undefined, Text$BsReactNative.make(undefined, undefined, undefined, undefined, undefined, undefined, undefined, undefined, undefined, Js_primitive.some(AppStyle.listIndex), undefined, undefined, undefined, undefined, undefined, undefined, point, /* array */[]))
                                                      ])),
                                              ReasonReact.element(undefined, undefined, View$BsReactNative.make(undefined, undefined, undefined, undefined, undefined, undefined, undefined, undefined, undefined, Js_primitive.some(AppStyle.listContent), undefined, undefined, undefined, undefined, undefined, undefined, undefined, undefined, undefined, undefined)(/* array */[
                                                        ReasonReact.element(undefined, undefined, Text$BsReactNative.make(undefined, undefined, undefined, undefined, undefined, undefined, openUrl, undefined, undefined, Js_primitive.some(AppStyle.title), undefined, undefined, undefined, undefined, undefined, undefined, title, /* array */[])),
                                                        ReasonReact.element(undefined, undefined, Text$BsReactNative.make(undefined, undefined, undefined, undefined, undefined, undefined, undefined, undefined, undefined, Js_primitive.some(AppStyle.domain), undefined, undefined, undefined, undefined, undefined, undefined, domain, /* array */[])),
                                                        ReasonReact.element(undefined, undefined, Text$BsReactNative.make(undefined, undefined, undefined, undefined, undefined, undefined, undefined, undefined, undefined, Js_primitive.some(AppStyle.timeAgoAndUser), undefined, undefined, undefined, undefined, undefined, undefined, timeAgoAndUser, /* array */[]))
                                                      ])),
                                              ReasonReact.element(undefined, undefined, View$BsReactNative.make(undefined, undefined, undefined, undefined, undefined, undefined, undefined, undefined, undefined, Js_primitive.some(AppStyle.listCommentAndFunc), undefined, undefined, undefined, undefined, undefined, undefined, undefined, undefined, undefined, undefined)(/* array */[ReasonReact.element(undefined, undefined, Text$BsReactNative.make(undefined, undefined, undefined, undefined, undefined, undefined, navigateToComment, undefined, undefined, undefined, undefined, undefined, undefined, undefined, undefined, undefined, commentsCount, /* array */[]))]))
                                            ]));
                            }), param);
              };
              var keyExtractor = function (_item, index) {
                return String(index);
              };
              var itemSeparatorComponent = function (param) {
                return FlatList$BsReactNative.separatorComponent((function (param) {
                              return ReasonReact.element(undefined, undefined, View$BsReactNative.make(undefined, undefined, undefined, undefined, undefined, undefined, undefined, undefined, undefined, Js_primitive.some(AppStyle.separator), undefined, undefined, undefined, undefined, undefined, undefined, undefined, undefined, undefined, undefined)(/* array */[]));
                            }), param);
              };
              return ReasonReact.element(undefined, undefined, FlatList$BsReactNative.make(data, renderItem, keyExtractor, Js_primitive.some(itemSeparatorComponent), undefined, undefined, undefined, undefined, undefined, undefined, undefined, undefined, undefined, undefined, undefined, onEndReached, 0.5, undefined, undefined, undefined, undefined, undefined, undefined, undefined, undefined, undefined, undefined, undefined, undefined, undefined, undefined)(/* array */[]));
            }),
          /* initialState */component[/* initialState */10],
          /* retainedProps */component[/* retainedProps */11],
          /* reducer */component[/* reducer */12],
          /* jsElementWrapped */component[/* jsElementWrapped */13]
        ];
}

exports.component = component;
exports.make = make;
/* component Not a pure module */
