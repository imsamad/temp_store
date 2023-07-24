import { render, screen } from '@testing-library/react';
import TodoFooter from '../TodoFooter';
import { BrowserRouter } from 'react-router-dom';
const MockTodoFooter = ({ numberOfIncompleteTasks }) => {
  return (
    <BrowserRouter>
      <TodoFooter numberOfIncompleteTasks={numberOfIncompleteTasks} />
    </BrowserRouter>
  );
};

test('Testing rendering of TodoFooter...', () => {
  render(<MockTodoFooter numberOfIncompleteTasks={5} />);
  const paraElem = screen.getByText(/5 tasks left/i);
  expect(paraElem).toBeInTheDocument();
  //   expect(paraElem).lastCalledWith
  //   expect(paraElem).lastReturnedWith
  //   expect(paraElem).not
  //   expect(paraElem).nthCalledWith
  //   expect(paraElem).nthReturnedWith
  //   expect(paraElem).rejects
  //   expect(paraElem).resolves
  //   expect(paraElem).toBe
  //   expect(paraElem).toBeCalled
  //   expect(paraElem).toBeCalledTimes
  //   expect(paraElem).toBeCalledWith
  //   expect(paraElem).toBeChecked
  //   expect(paraElem).toBeCloseTo
  //   expect(paraElem).toBeDefined
  //   expect(paraElem).toBeDisabled
  //   expect(paraElem).toBeFalsy
  //   expect(paraElem).toBeEmptyDOMElement
  //   expect(paraElem).toBeEnabled
  //   expect(paraElem).toBeGreaterThan
  //   expect(paraElem).toBeGreaterThanOrEqual
  //   expect(paraElem).toBeInTheDocument
  //   expect(paraElem).toBeInstanceOf
  //   expect(paraElem).toBeInvalid
  //   expect(paraElem).toBeLessThan
  //   expect(paraElem).toBeLessThanOrEqual
  //   expect(paraElem).toBeNaN
  //   expect(paraElem).toBeNull
  //   expect(paraElem).toBePartiallyChecked
  //   expect(paraElem).toBeRequired
  //   expect(paraElem).toBeTruthy
  //   expect(paraElem).toBeUndefined
  //   expect(paraElem).toBeValid
  //   expect(paraElem).toBeVisible
  //   expect(paraElem).toContain
  //   expect(paraElem).toContainElement
  //   expect(paraElem).toContainEqual
  //   expect(paraElem).toContainHTML
  //   expect(paraElem).toEqual
  //   expect(paraElem).toHaveAccessibleDescription
  //   expect(paraElem).toHaveAccessibleName
  //   expect(paraElem).toHaveAttribute
  //   expect(paraElem).toHaveBeenCalled
  //   expect(paraElem).toHaveBeenCalledTimes
  //   expect(paraElem).toHaveBeenCalledWith
  //   expect(paraElem).toHaveBeenLastCalledWith
  //   expect(paraElem).toHaveBeenNthCalledWith
  //   expect(paraElem).toHaveClass
  //   expect(paraElem).toHaveDisplayValue
  //   expect(paraElem).toHaveErrorMessage
  //   expect(paraElem).toHaveFocus
  //   expect(paraElem).toHaveFormValues
  //   expect(paraElem).toHaveLastReturnedWith
  //   expect(paraElem).toHaveReturnedTimes
  //   expect(paraElem).toHaveLength
  //   expect(paraElem).toHaveNthReturnedWith
  //   expect(paraElem).toHaveStyle
  //   expect(paraElem).toHaveTextContent
  //   expect(paraElem).toHaveValue
  //   expect(paraElem).toMatch
  //   expect(paraElem).toMatchInlineSnapshot
  //   expect(paraElem).toMatchObject
  //   expect(paraElem).toMatchSnapshot
  //   expect(paraElem).toReturn
  //   expect(paraElem).toReturnTimes
  //   expect(paraElem).toReturnWith
  //   expect(paraElem).toStrictEqual
  //   expect(paraElem).toThrow
  //   expect(paraElem).toThrowError
  //   expect(paraElem).toThrowErrorMatchingInlineSnapshot
  //   expect(paraElem).toThrowErrorMatchingSnapshot.
});
