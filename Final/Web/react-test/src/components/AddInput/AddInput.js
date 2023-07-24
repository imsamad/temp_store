import React from 'react';
import './AddInput.css';
import { v4 } from 'uuid';
// import TodoList from '../TodoList/TodoList'

function AddInput({ setTodos, todos }) {
  // const [todo, setTodo] = useState('');
  const todo = React.useRef('');

  const addTodo = () => {
    let updatedTodos = [
      ...todos,
      {
        id: v4(),
        task: todo.current.value,
        completed: false,
      },
    ];
    setTodos(updatedTodos);
    // setTodo('');
    todo.current.value = '';
  };

  return (
    <div className="input-container">
      <input
        className="input"
        ref={todo}
        // value={todo}
        // onChange={(e) => setTodo(e.target.value)}
        placeholder="Add a new task here..."
      />
      <button className="add-btn" onClick={addTodo}>
        Add
      </button>
    </div>
  );
}

export default AddInput;
