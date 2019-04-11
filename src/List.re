open Data;
let places = Resto.places;
let getElements =
    (places: array(Resto.resto), term: string) => {
    // Js.log2(Resto.search(places, term), term)    
    Resto.search(places, term)->Belt.Array.map(p =>
    <li key={p.id}>
      <img
        src={p.img.url}
        title={
          switch (p.img.attrUrl) {
          | None => "No attribution"
          | Some(url) => url
          }
        }
      />
      {React.string(p.name)}
    </li>
  );
};

[@react.component]
let make = (~term: string) => {
  let elements = getElements(places, term);
  <>
    <span>
      <h3>
        {React.string("My Lovely Restaurant List. Total: ")}
        {React.string(string_of_int(Js.Array.length(elements)))}
      </h3>
    </span>
    <ul> {React.array(elements)} </ul>
  </>;
};
