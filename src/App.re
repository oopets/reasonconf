[@react.component]
let make = () => {
  let (term, setTerm) = React.useState(() => "");
  <>
    <div>
      <input
        id="search"
        value={term}
        onChange={event => setTerm(ReactEvent.Form.target(event)##value) } 
        placeholder="Dude, just start typing!"
      />
    </div>
    <List term />
  </>;
};