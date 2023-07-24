import { render, screen } from '@testing-library/react';
import App from './App';
import { BrowserRouter } from 'react-router-dom';
const MockApp = () => (
  <BrowserRouter>
    <App />
  </BrowserRouter>
);

test('renders learn react link', () => {
  render(<MockApp />);
  // const linkElement = screen.getByText(/learn react/i);
  //Accessible By Everyone
  // screen.findAllByLabelText
  // screen.findAllByPlaceholderText
  // screen.findAllByRole
  // screen.findAllByText

  // Semantic queries
  // screen.findAllByAltText
  // screen.findAllByTitle

  // Test ID
  // screen.findAllByTestId

  // screen.findAllByDisplayValue

  // findBy
  // findAllBy
  // getBy
  // getAll
  // queryBy
  // queryAllBy
});
