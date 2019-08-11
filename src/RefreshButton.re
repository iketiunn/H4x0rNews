/* Hide it when scrolling down` */
open ReactNative;
let refreshImageSource =
  Image.Source.fromRequired(Packager.require("../assets/refresh.png"));

let component = ReasonReact.statelessComponent("RefreshButton");
[@react.component]
let make = (~onPress, ()) =>
  ReactCompat.useRecordApi({
    ...component,
    render: _self =>
      <TouchableOpacity
        onPress style=AppStyle.RefreshButton.floatingActionButton>
        <Image style=AppStyle.Common.image source=refreshImageSource />
      </TouchableOpacity>,
  });