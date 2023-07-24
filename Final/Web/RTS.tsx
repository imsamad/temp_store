type propsType = {};

const index = () => {
  return (
    <div>
      <button></button>
    </div>
  );
};

type btnProp = {
  onClick: () => null;
};

const Button = ({ onClick }: btnProp) => {
  return <button onClick={onClick}></button>;
};
