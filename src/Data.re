module Resto = {
  type image = {
    url: string,
    attr: string,
    attrUrl: option(string),
  };

  type coordinate = {
    lat: float,
    lon: float,
  };

  type resto = {
    id: string,
    name: string,
    desc: string,
    img: image,
    address: string,
    coord: coordinate,
    phone: option(string),
    email: option(string),
  };

  let places = [|
    {
      id: "0155d046-ff03-4d52-a98e-e48c887116af",
      name: "Chez Olivier",
      desc: "French cuisine",
      img: {
        url: "https://media-cdn.tripadvisor.com/media/photo-o/10/d1/fd/43/caption.jpg",
        attr: "Mine",
        attrUrl: None,
      },
      address: "1 Rue du Pont, Paris, 01000",
      coord: {
        lat: 10.10,
        lon: 99.23,
      },
      phone: Some("+00342342844"),
      email: Some("olivier1903@gmail.com"),
    },
    {
      id: "fccc9b96-d611-4df9-bee5-ea0097779ba1",
      name: {j|Très Branché|j},
      desc: "French modern cuisine",
      img: {
        url: "https://scontent-vie1-1.xx.fbcdn.net/v/t31.0-8/10750410_1514324315519572_5477618609869746935_o.jpg?_nc_cat=106&_nc_ht=scontent-vie1-1.xx&oh=4eb18f9c6278a04413862cc6a8a9d0a3&oe=5D472B7E",
        attr: "(c) Très Branché",
        attrUrl: Some("Does not matter"),
      },
      address: "Lysenka str. 4, Kiev 01030, Ukraine",
      coord: {
        lat: 50.448889,
        lon: 30.513333,
      },
      phone: Some("+380 44 278 6125"),
      email: Some("http://tres-fr.com/en/"),
    },
    {
      id: "199c12be-e8b9-4064-b9c5-48d98dac1b94",
      name: "Alchemist Bar",
      desc: "Just a bar",
      img: {
        url: "https://media-cdn.tripadvisor.com/media/photo-w/10/f2/f3/bd/20170928-205332-largejpg.jpg",
        attr: "(c) Alchemist Bar",
        attrUrl: None,
      },
      address: "Shota Rustaveli, 12, Kiev 01023, Ukraine",
      coord: {
        lat: 50.438611,
        lon: 30.523056,
      },
      phone: Some("+380 96 008 7070"),
      email: Some("https://www.facebook.com/AlchemistBarKiev"),
    },
  |];

  let search = (places, str: string) =>
    Belt.Array.keep(places, p => Js.String.includes(str, p.name));
  /*search(places, "che")->Belt.Array.map(p => p.name)|>Js.log;*/
};