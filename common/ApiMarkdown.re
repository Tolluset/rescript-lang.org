open Util.ReactStuff;

/*
    We use some custom markdown styling for the Belt docs to make
    it easier on the eyes
 */
open Markdown;

module InvisibleAnchor = {
  [@react.component]
  let make = (~id: string) => {
    let style = ReactDOMRe.Style.make(~position="absolute", ~top="-1rem", ());
    <span className="relative" ariaHidden=true> <a id style /> </span>;
  };
};

module H1 = {
  [@react.component]
  let make = (~children) => {
    <h1
      className="text-6xl leading-1 mb-2 font-sans font-medium text-night-dark">
      children
    </h1>;
  };
};

module H2 = {
  // We will currently hide the headline, to keep the structure,
  // but having an Elm like documentation
  [@react.component]
  let make = (~children) => {
    <>
      // Here we know that children is always a string (## headline)
      <InvisibleAnchor id={children->Unsafe.elementAsString} />
      <div className="border-b border-gray-200 my-20" />
    </>;
  };
};

module Pre = {
  [@react.component]
  let make = (~children) => {
    <pre className="mt-2 mb-4 block"> children </pre>;
  };
};

module P = {
  [@react.component]
  let make = (~children) => {
    <p className="mt-3 leading-4"> children </p>;
  };
};

let default =
  Mdx.Components.t(
    ~p=P.make,
    ~li=Li.make,
    ~h1=H1.make,
    ~h2=H2.make,
    ~h3=H3.make,
    ~h4=H4.make,
    ~h5=H5.make,
    ~ul=Ul.make,
    ~ol=Ol.make,
    ~a=A.make,
    ~thead=Thead.make,
    ~th=Th.make,
    ~td=Td.make,
    ~pre=Pre.make,
    ~inlineCode=InlineCode.make,
    ~code=Code.make,
    (),
  );
