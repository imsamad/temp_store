import { screen, render } from '@testing-library/react';

import Header from '../Header';

test('tesing header', () => {
  render(<Header title="MyHeader" />);
  const headingElm = screen.getByText(/myheader/i);
  expect(headingElm).toBeInTheDocument();
});
