open BsReactNative;

/**
 * TODO:
 * - Handle webview link
 */
let screenWidth = Dimensions.get(`window)##width;
type state = {webViewHeight: float};
type action =
  | Loaded(float);
let component = ReasonReact.reducerComponent("ResizedWebView");
let make = (~content: string, _children) => {
  ...component,
  initialState: () => {webViewHeight: 0.0},
  reducer: (action, _state) =>
    switch (action) {
    | Loaded(height) => ReasonReact.Update({webViewHeight: height})
    },
  render: self => {
    let setHight = height => self.send(Loaded(height));
    let script = "<script> window.onload = function () { window.location.hash = 1; document.title = window.innerHeight || document.documentElement.clientHeight || document.body.clientHeight; } </script>";
    let html = "<div>" ++ content ++ "</div>" ++ script;
    <View>
      <WebView
        style={
          Style.style([
            Style.backgroundColor(String("#00000000")),
            Style.width(Pt(float_of_int(screenWidth))),
            Style.height(Pt(self.state.webViewHeight)),
          ])
        }
        scalesPageToFit={Platform.os() == Platform.Android}
        source={WebView.sourceHtml(~html, ())}
        scrollEnabled=false
        automaticallyAdjustContentInsets=true
        onNavigationStateChange={
          event => {
            let unsafeHeight = WebView.EventTypes.titleGet(event);
            switch (unsafeHeight) {
            | Some(h) =>
              let isNum = Js.String.match(Js.Re.fromString("[0-9]+"), h);
              switch (isNum) {
              | Some(mached) =>
                mached
                |> Array.to_list
                |> List.hd
                |> float_of_string
                |> setHight
              | None => ()
              };
              ();
            | None => ()
            };
          }
        }
      />
    </View>;
  },
};