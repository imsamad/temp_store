import { screen, render, fireEvent } from '@testing-library/react';
import userEvent from '@testing-library/user-event';
import AddInput from '../AddInput';
const mockedSetTodos = jest.fn();
describe('Add Input', () => {
  it('should render input element', async () => {
    render(<AddInput todos={[]} setTodos={mockedSetTodos} />);
    const inputElm = screen.getByPlaceholderText(/Add a new task here.../i);
    expect(inputElm).toBeInTheDocument();
  });

  it('should be able to type input', async () => {
    render(<AddInput todos={[]} setTodos={mockedSetTodos} />);
    const inputElm = screen.getByPlaceholderText(/Add a new task here.../i);
    fireEvent.change(inputElm, { target: { value: 'Go grocery Shopping' } });
    expect(inputElm.value).toBe('Go grocery Shopping');
  });

  it('should have empty input on clicked of add btn...', async () => {
    render(<AddInput todos={[]} setTodos={mockedSetTodos} />);
    const inputElm = screen.getByPlaceholderText(/Add a new task here.../i);
    const btnElm = screen.getByRole('button', { name: /add/i });
    fireEvent.change(inputElm, { target: { value: 'Go grocery Shopping' } });
    fireEvent.click(btnElm);
    expect(inputElm.value).toBe('');
  });
});
