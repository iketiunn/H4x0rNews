open BsReactNative;

let component = ReasonReact.statelessComponent("NewsFlatList");
let make = (~data, _children) => {
  ...component,
  render: _self => {
    /* Need to specified type! */
    let renderItem =
      /* Make a card view */
      FlatList.renderItem((news: FlatList.renderBag(Data.news)) => {
        let domain =
          switch (news.item.domain) {
          | Some(str) => str
          | None => ""
          };
        <View> <Text value={news.item.title} /> <Text value=domain /> </View>;
      });
    /* Need to specified type! */
    let keyExtractor = (item: Data.news, _index) => string_of_int(item.id);
    let itemSeparatorComponent =
      FlatList.separatorComponent(_ => <View style=AppStyle.separator />);
    <FlatList data keyExtractor renderItem itemSeparatorComponent />;
  },
};