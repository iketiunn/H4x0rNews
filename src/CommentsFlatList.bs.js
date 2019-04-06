// Generated by BUCKLESCRIPT VERSION 4.0.7, PLEASE EDIT WITH CARE
'use strict';

var List = require("bs-platform/lib/js/list.js");
var $$Array = require("bs-platform/lib/js/array.js");
var AppStyle = require("./AppStyle.bs.js");
var HtmlView = require("./HtmlView.bs.js");
var ReasonReact = require("reason-react/src/ReasonReact.js");
var Js_primitive = require("bs-platform/lib/js/js_primitive.js");
var Text$BsReactNative = require("bs-react-native/src/components/text.js");
var View$BsReactNative = require("bs-react-native/src/components/view.js");
var FlatList$BsReactNative = require("bs-react-native/src/components/flatList.js");

var component = ReasonReact.statelessComponent("CommentsFlatList");

function make(data, _children) {
  var renderComment = function (comments) {
    var renderItem = function (param) {
      return FlatList$BsReactNative.renderItem((function (comment) {
                    var match = comment[/* item */0][/* user */2];
                    var user = match !== undefined ? match : "[deleted]";
                    var userAndTimeAge = user + (" " + comment[/* item */0][/* time_ago */4]);
                    var match$1 = List.length(comment[/* item */0][/* comments */6]) > 0;
                    return ReasonReact.element(undefined, undefined, View$BsReactNative.make(undefined, undefined, undefined, undefined, undefined, undefined, undefined, undefined, undefined, Js_primitive.some(AppStyle.Comment[/* container */0]), undefined, undefined, undefined, undefined, undefined, undefined, undefined, undefined, undefined, undefined)(/* array */[
                                    ReasonReact.element(undefined, undefined, View$BsReactNative.make(undefined, undefined, undefined, undefined, undefined, undefined, undefined, undefined, undefined, Js_primitive.some(AppStyle.Comment[/* item */1](comment[/* item */0][/* level */1])), undefined, undefined, undefined, undefined, undefined, undefined, undefined, undefined, undefined, undefined)(/* array */[
                                              ReasonReact.element(undefined, undefined, Text$BsReactNative.make(undefined, undefined, undefined, undefined, undefined, undefined, undefined, undefined, undefined, Js_primitive.some(AppStyle.Common[/* grayFontColor */0]), undefined, undefined, undefined, undefined, undefined, undefined, userAndTimeAge, /* array */[])),
                                              ReasonReact.element(undefined, undefined, HtmlView.make(comment[/* item */0][/* content */5], /* array */[]))
                                            ])),
                                    match$1 ? renderComment(comment[/* item */0][/* comments */6]) : ReasonReact.element(undefined, undefined, View$BsReactNative.make(undefined, undefined, undefined, undefined, undefined, undefined, undefined, undefined, undefined, undefined, undefined, undefined, undefined, undefined, undefined, undefined, undefined, undefined, undefined, undefined)(/* array */[]))
                                  ]));
                  }), param);
    };
    var keyExtractor = function (_item, index) {
      return String(index);
    };
    return ReasonReact.element(undefined, undefined, FlatList$BsReactNative.make($$Array.of_list(comments), renderItem, keyExtractor, undefined, undefined, undefined, undefined, undefined, undefined, undefined, undefined, undefined, undefined, undefined, undefined, undefined, undefined, undefined, undefined, undefined, undefined, undefined, undefined, undefined, undefined, undefined, undefined, undefined, undefined, undefined, Js_primitive.some(AppStyle.CommentsPage[/* paddingLeft */0]))(/* array */[]));
  };
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
              if (List.length(data) > 0) {
                return renderComment(data);
              } else {
                return ReasonReact.element(undefined, undefined, View$BsReactNative.make(undefined, undefined, undefined, undefined, undefined, undefined, undefined, undefined, undefined, undefined, undefined, undefined, undefined, undefined, undefined, undefined, undefined, undefined, undefined, undefined)(/* array */[ReasonReact.element(undefined, undefined, Text$BsReactNative.make(undefined, undefined, undefined, undefined, undefined, undefined, undefined, undefined, undefined, undefined, undefined, undefined, undefined, undefined, undefined, undefined, "End ot the thread", /* array */[]))]));
              }
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
