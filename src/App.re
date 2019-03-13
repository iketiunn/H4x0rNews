/* Should be a entry for News List */
open BsReactNative;

let component = ReasonReact.statelessComponent("App");
let onPress = () => Alert.alert(~title="alert", ~message="yoyo", ());

let make = _children => {
  ...component,
  render: _self =>
    <View
      style=Style.(
        style([flex(1.), justifyContent(Center), alignItems(Center)])
      )>
      <ReasonExpo.LinearGradient
        colors=[|"#DD4B39", "#C62C19"|]
        style=Style.(style([padding(Pt(12.)), borderRadius(12.)]))>
        <Text style=Style.(style([color(String("white"))]))>
          {ReasonReact.string("To get started, edit App.re!")}
        </Text>
      </ReasonExpo.LinearGradient>
      <Button title="Go to list" onPress />
    </View>,
};

let default = ReasonReact.wrapReasonForJs(~component, _jsProps => make([||]));