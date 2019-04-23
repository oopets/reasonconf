open Data;
let places = Resto.places;

let imgStyle =
  ReactDOMRe.Style.make(~height="80px", ~width="auto", ~margin="10px", ());

let gradient =
  ReactDOMRe.Style.make(
    ~backgroundImage="linear-gradient(grey, transparent)",
    ~height="100%",
    ~width="100%",
    ~padding="20px 0 0 20px",
    (),
  );

let getElements = (places: array(Resto.resto), term: string) => {
  // Js.log2(Resto.search(places, term), term)
  Resto.search(places, term)
  ->Belt.Array.map(p => {
      Js.log(p.img.url);
      let liStyle =
        ReactDOMRe.Style.make(
          ~backgroundImage="url(" ++ p.img.url ++ ")",
          ~backgroundPosition="center",
          (),
        );
      <li
        key={p.id}
        style=liStyle
        title={
          switch (p.img.attrUrl) {
          | None => "No attribution"
          | Some(url) => url
          }
        }>
        <span style={gradient}> {React.string(p.name)} </span>
      </li>;
    });
};

let headerStyle =
  ReactDOMRe.Style.make(~color="#444444", ~fontSize="20px", ());

[@react.component]
let make = (~term: string) => {
  let elements = getElements(places, term);
  <>
    <span>
      <h3 style=headerStyle>
        {React.string("My Lovely Restaurant List. Total: ")}
        {React.string(string_of_int(Js.Array.length(elements)))}
      </h3>
    </span>
    <ul> {React.array(elements)} </ul>
  </>;
};