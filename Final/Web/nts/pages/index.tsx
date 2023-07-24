import React from 'react';

// type reducerInstance = {
//   CounterType: {
//     count: number;
//   }
//   CounterAction: {
//     payload: number;
//     type: 'increment' | 'decrement';
//   }
// };
type CounterType = {
  count: number;
};
type CounterAction = {
  payload: number;
  type: 'increment' | 'decrement';
};
function reducer(state: CounterType, action: CounterAction) {
  switch (action.type) {
    case 'increment':
      return { count: state.count + action.payload };
    case 'decrement':
      return { count: state.count - action.payload };
    default:
      return state;
  }
}
type AuthUser = {
  name: string;
  age: number;
};
function Index() {
  const [state, setstate] = React.useState<AuthUser | null>(null);
  // If u r conffident that very soon the state would update as that...
  // const [state, setstate] = React.useState<AuthUser>({} as AuthUser);
  // user.name !user?.name
  const handleSetState = () => () => {
    setstate({ name: 'abdus samad', age: 24 });
  };
  const initState: CounterType = {
    count: 0,
  };
  const [count, disptch] = React.useReducer(reducer, initState);

  return (
    <div>
      <Compo
        handleSetState={handleSetState}
        tupleType="success"
        handleClick={(e) => {}}
        styles={{ border: '1px solid red' }}
      >
        <h2>Ok</h2>
      </Compo>
    </div>
  );
}

export default Index;
type propTypes = {
  handleSetState: () => React.Dispatch<React.SetStateAction<AuthUser>>;
  arrObj?: { abc?: string; xyz: number }[];
  tupleType: 'success' | 'fail';
  handleClick: (e: React.MouseEvent<HTMLButtonElement>) => void;
  // It means e is an MouseEvent ,but scaffold it with btn event functionality.
  children: React.ReactNode | string | HTMLElement;
  handleChange?: (e: React.ChangeEvent<HTMLInputElement>) => void;

  styles: React.CSSProperties;
};

const Compo = (props: propTypes) => {
  return (
    <div>
      {JSON.stringify(props)}
      <button onClick={(e) => props.handleClick(e)}></button>
      <input type="text" onChange={props.handleChange} />
    </div>
  );
};
