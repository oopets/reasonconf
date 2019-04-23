let style =
  ReactDOMRe.Style.make(
    ~border="2px solid mediumaquamarine",
    ~borderRadius="6px",
    ~padding="10px",
    ~fontSize="20px",
    ~color="mediumaquamarine",
    (),
  );

[@react.component]
let make = () => {
  let (term, setTerm) = React.useState(() => "");
  <>
    <div>
      <input
        style
        id="search"
        value=term
        onChange={event => setTerm(ReactEvent.Form.target(event)##value)}
        placeholder="Dude, just start typing!"
      />
    </div>
    <List term />
  </>;
};