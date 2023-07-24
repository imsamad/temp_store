import { screen, render, fireEvent } from '@testing-library/react';
import Todo from '../Todo';
import { BrowserRouter } from 'react-router-dom';
const MockTodo = (props) => {
  return (
    <BrowserRouter>
      <Todo {...props} />
    </BrowserRouter>
  );
};

const addTasks = (tasks) => {
  const inputElm = screen.getByPlaceholderText(/Add a new task here.../i);
  const btnElm = screen.getByRole('button', { name: /Add/i });
  tasks.forEach((todo) => {
    fireEvent.change(inputElm, { target: { value: todo } });
    fireEvent.click(btnElm);
  });
};
describe('Todo', () => {
  it('should render input element', async () => {
    render(<MockTodo />);
    addTasks(['Shopping one', 'Shopping two', 'Shopping three']);
    let divElm = screen.getAllByTestId('task-container');
    // expect(divElm).not.toHaveClass('todo-item-active');
    expect(divElm.length).toBe(3);
  });

  it('should have  todo-item-active class', async () => {
    render(<MockTodo />);
    addTasks(['Shopping one']);
    let divElm = screen.getByTestId('task-container');
    expect(divElm).not.toHaveClass('todo-item-active');
    fireEvent.click(divElm);
    expect(divElm).toHaveClass('todo-item-active');
    // expect(divElm.length).toBe(3);
  });
});
