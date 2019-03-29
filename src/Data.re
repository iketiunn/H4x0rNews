type news = {
  id: int,
  title: string,
  points: option(int),
  user: option(string),
  time: int,
  time_ago: string,
  comments_count: int,
  type_: string,
  url: string,
  domain: option(string),
};
type newsList = list(news);
type comment = {
  id: int,
  level: int,
  user: option(string),
  time: int,
  time_ago: string,
  content: string,
  comments: list(option(comment)),
};
type story = {
  id: int,
  title: string,
  points: option(int),
  user: option(string),
  time: int,
  time_ago: string,
  type_: string,
  url: string,
  domain: option(string),
  comments: list(comment),
};
module Decode = {
  let news = json: news =>
    Json.Decode.{
      id: json |> field("id", int),
      title: json |> field("title", string),
      points: json |> optional(field("points", int)),
      user: json |> optional(field("user", string)),
      time: json |> field("time", int),
      time_ago: json |> field("time_ago", string),
      comments_count: json |> field("comments_count", int),
      type_: json |> field("type", string), /* type is reserved, use type_ as convention */
      url: json |> field("url", string),
      domain: json |> optional(field("domain", string)),
    };
  let newsList = json: list(news) => Json.Decode.(json |> list(news));

  let rec comment = json: comment =>
    Json.Decode.{
      id: json |> field("id", int),
      level: json |> field("level", int),
      user: json |> optional(field("user", string)),
      time: json |> field("time", int),
      time_ago: json |> field("time_ago", string),
      content: json |> field("content", string),
      comments: json |> field("comments", list(optional(comment))),
    };

  let story = json: story =>
    Json.Decode.{
      id: json |> field("id", int),
      title: json |> field("title", string),
      points: json |> optional(field("points", int)),
      user: json |> optional(field("user", string)),
      time: json |> field("time", int),
      time_ago: json |> field("time_ago", string),
      type_: json |> field("type", string),
      url: json |> field("url", string),
      domain: json |> optional(field("domain", string)),
      comments: json |> field("comments", list(comment)),
    };
};
let domain = "https://ikewat-hnapi.now.sh";
let fetchNewList = (~id="1", ()) =>
  Js.Promise.(
    Fetch.fetch(domain ++ "/news?page=" ++ id)
    |> then_(Fetch.Response.json)
    |> then_(json => json |> Decode.newsList |> resolve)
  );
let fetchStory = id =>
  Js.Promise.(
    Fetch.fetch(domain ++ "/item/" ++ id)
    |> then_(Fetch.Response.json)
    |> then_(json => json |> Decode.story |> resolve)
  );